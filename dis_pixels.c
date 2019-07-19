/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:15:33 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/19 11:18:11 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dis_pixels(t_mlx *mlx)
{
	int		i =  0;
	int		j;

	while (i < mlx->heigth)
	{
		j = 0;
		while (j < mlx->width)
		{
			printf("(%d, %d)\n", mlx->pixs[i][j].x, mlx->pixs[i][j].y);	
			j++;
		}
		i++;
	}
}
