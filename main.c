/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:41:22 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/15 14:39:36 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	t_pixel	**pixels;
	int		i;
	int		j;
	int		width;
	int		heigth;

	if (ac != 2)
	{
		ft_putendl("Error: Invalid argument");
		return (1);
	}
	if (get_dim(av[1], &width, &heigth) == 0)
	{
		ft_putendl("Error: can't get dimensions");
		return (1);
	}
	ft_putstr("width: ");
	ft_putnbr(width);
	ft_putstr("heigth: ");
	ft_putnbr(heigth);
	ft_putendl("");
	pixels = read_file(av[1], width, heigth);
	if (pixels)
	{
		i = 0;
		while (i < heigth)
		{
			j = 0;
			while (j < width)
			{
				ft_putnbr(pixels[i][j].z);
				ft_putstr(",");
				ft_putnbr(pixels[i][j++].color);
				ft_putstr(" ");
			}
			ft_putendl("");
			i++;
		}
	}
	else
		ft_putendl("Can't Read file");
	del_pixels(pixels, heigth);
	return (0);
}
