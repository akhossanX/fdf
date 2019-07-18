/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:19:29 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/18 22:23:21 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_params(t_param param, t_pixel p1, t_pixel p2)
{
	param.x0 = p1.x;
	param.x1 = p2.x;
	param.y0 = p1.y;
	param.y1 = p2.y;
	param.dx = abs(p2.x - p1.x);
	param.sx = p1.x < p2.x ? 1 : -1;
	param.dy = -abs(p2.y - p1.y);
	param.sy = p1.y < p2.y ? 1 : -1;
	param.d = param.dy + param.dx;
}

void	draw_line(t_mlx *mlx, t_pixel p1, t_pixel p2)
{
	t_param	param;

	printf("(%d, %d) --> (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
	init_params(param, p1, p2);
	while (1)
	{
		mlx_pixel_put(mlx->pan, mlx->win, param.x0, param.y0, 0xFFFFFF);
		param.error = 2 * param.d;
		if (param.error >= param.dy)
		{
			if (param.x0 == param.x1)
				break ;
			param.d += param.dy;
			param.x0 += param.sx;
		}
		if (param.error <= param.dx)
		{
			if (param.y0 == param.y1)
				break ;
			param.d += param.dx;
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
			draw_line(mlx, mlx->pixs[i][j], mlx->pixs[i][j + 1]);
		i++;
	}
	//Draw Vertical
	j = 0;
	while (j < mlx->width)
	{
		i = -1;
		while (++i < mlx->heigth - 1)
			draw_line(mlx, mlx->pixs[i][j], mlx->pixs[i + 1][j]);
		j++;
	}
}
