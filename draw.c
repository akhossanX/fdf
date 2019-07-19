/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:19:29 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/19 11:54:22 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define XOFF	100
#define YOFF	100


void	init_params(t_param *param, t_pixel p1, t_pixel p2)
{
	param->x0 = p1.x;
	param->y0 = p1.y;
	param->x1 = p2.x;
	param->y1 = p2.y;
	param->dx = abs(p2.x - p1.x);
	param->dy = -abs(p2.y - p1.y);
	param->sx = p1.x < p2.x ? 1 : -1;
	param->sy = p1.y < p2.y ? 1 : -1;
	param->err = param->dx + param->dy;
}


void	draw_line(t_mlx *mlx, t_pixel p1, t_pixel p2)
{
	t_param	param;

	init_params(&param, p1, p2);
	printf("%d, %d\n", param.x0, param.y0);
	while (1)
	{
		mlx_pixel_put(mlx->pan, mlx->win, param.x0 + XOFF, param.y0 + YOFF, 0xffffff);
		param.err2 = 2 * param.err;
		if (param.err2 >= param.dy)
		{
			if (param.x0 == param.x1)
				break ;
			param.err += param.dy;
			param.x0 += param.sx;
		}
		if (param.err2 <=  param.dx)
		{
			if (param.y0 == param.y1)
				break ;
			param.err += param.dx;
			param.y0 += param.sy;
		}
	}
}

void	draw_map(t_mlx *mlx)
{
	int		i;
	int		j;	

	i = 0;
	//Draw horizontal
	while (i < mlx->heigth)
	{
		j = -1;
		while (++j < mlx->width - 1)
			draw_line(mlx, mlx->proj[i][j], mlx->proj[i][j + 1]);
		i++;
	}
	//Draw Vertical
	j = 0;
	while (j < mlx->width)
	{
		i = -1;
		while (++i < mlx->heigth - 1)
			draw_line(mlx, mlx->proj[i][j], mlx->proj[i + 1][j]);
		j++;
	}
}
