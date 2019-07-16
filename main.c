/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:41:22 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/16 13:38:08 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	t_pixel	**pixels;
	int		width;
	int		heigth;

	if (ac != 2 || get_dim(av[1], &width, &heigth) == 0)
	{
		ft_putendl("Error: Invalid Map");
		return (1);
	}
	pixels = read_file(av[1], width, heigth);

	/*
	**	draw a window and put pixels inside
	**
	*/
	void	*mlx;
	void	*win;
	void	*img;
	int		endian;
	int		size_line;
	int		bpp;
	unsigned char	*data;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 3000, 1500, "FDF");
	img = mlx_new_image(mlx, width * 10, heigth * 10);
	data = (unsigned char*)mlx_get_data_addr(img, &bpp, &size_line, &endian);
	int		i;
	int		j;
	int		scale = 2;
	int		xp;
	int		yp;
	i = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			xp = (i - j) * scale * cos(0.523599);
			yp = -pixels[i][j].z + (i + j) * scale * sin(0.523599);
			mlx_pixel_put(mlx, win, xp + 1500, yp + 150, pixels[i][j].color);
			j++;
		}
		i++;
	}
	//mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img);

	del_pixels(pixels, heigth);
	return (0);
}
/*
	i = 0;
	int		k;
	k = 0;
	while (i < heigth)
	{
		j = 0;
		while (j < width)
		{
			printf("i: %d, j: %d\n", pixels[i][j].y, pixels[i][j].x);
			k = pixels[i][j].y * width + pixels[i][j].x;
			data[k] = pixels[i][j].color;
			j++;
		}
		i++;
	}
*/
