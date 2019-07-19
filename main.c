/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:41:22 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/20 00:01:31 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_puterror(int err)
{
	if (err == 0)
		ft_putendl("Usage: ./fdf [map_file]");
	if (err == 1)
		ft_putendl("Error: invalid file");
	if (err == 2)
		ft_putendl("Error: allocation failure");
	exit(1);
}

t_mlx	*mlx_new(char *arg)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		ft_puterror(2);
	if (get_dim(arg, &mlx->width, &mlx->heigth) == 0)
		ft_puterror(1);
	mlx->pan = mlx_init();
	mlx->win = mlx_new_window(mlx->pan, WIDTH, HEIGTH, TITLE);
	mlx->img = mlx_new_image(mlx->pan, WIDTH, HEIGTH);
	mlx->zoom = 1;
	mlx->cols = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size,\
			&mlx->endian);
	mlx->pixs = read_file(arg, mlx->width, mlx->heigth);
	if (!clone_pixels(mlx, 1))
	{
		//TODO: destroy pixels
		ft_puterror(2);
	}
	mlx->angle_x = 0.0;
	mlx->angle_y = 0.0;
	//render(mlx, mlx->proj);
	return (mlx);
}

void	iso(t_mlx *mlx, int i, int j)
{

	mlx->proj[i][j].x = (mlx->pixs[i][j].x - mlx->pixs[i][j].y)\
			* cos(0.523599);
	mlx->proj[i][j].y = -mlx->pixs[i][j].z * Z_ZOOM +\
	(mlx->pixs[i][j].x +mlx->pixs[i][j].y) * sin(0.523599);
}

int		clone_pixels(t_mlx *mlx, int pjct)
{
	int		i;
	int		j;


	if (!(mlx->proj = (t_pixel **)malloc(sizeof(t_pixel*) * mlx->heigth)))
		return (0);
	i = 0;
	while (i < mlx->heigth)
	{
			if (!(mlx->proj[i] = (t_pixel*)malloc(sizeof(t_pixel) * mlx->width)))
				return (0);
			j = 0;
			while (j < mlx->width)
			{
				if (pjct == 1)
					iso(mlx, i, j);
			//	else if (pjct == 2)
			//		parallel(mlx, i, j);	
			//	else if (pjct == 3)
			//		mirror(mlx, i, j);
				mlx->proj[i][j].color = mlx->pixs[i][j].color;
				j++;
			}
			i++;
	}
	return (1);
}


int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac != 2)
		ft_puterror(0);
	mlx = mlx_new(av[1]);
	//dis_pixels(mlx);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->pan, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->pan);
	del_pixels(mlx->pixs, mlx->heigth);
	del_pixels(mlx->proj, mlx->heigth);
	return (0);
}
