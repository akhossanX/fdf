/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:17:47 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/15 10:36:10 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./gnl/get_next_line.h"
# include <fcntl.h>
# define DEBUG	ft_putendl("Oh Yeah..Here")

#include <stdio.h>

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_pixel;

t_pixel			**read_file(char *fpath, int width, int heigth);
int				get_dim(char *fpath, int *width, int *heigth);
t_pixel			**to_pixel(int fd, int width, int height);
void			del_str_array(char **pixels);
void			del_pixels(t_pixel **pixels, int size);
void			fill_pixels_row(t_pixel *pix, int r, int width, char **s);
void			disp(char **s);

#endif
