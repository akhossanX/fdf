/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:17:47 by akhossan          #+#    #+#             */
/*   Updated: 2019/07/18 21:42:52 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./gnl/get_next_line.h"
# include <fcntl.h>
# include "./minilibx_macos/mlx.h"
# include <math.h>
# define WIDTH	1280
# define HEIGTH	720
# define TITLE	"FDF"

#include <stdio.h>

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_pixel;

typedef struct		s_mlx
{
	//Map width and heigth (read from file)
	//Defines how many pixels are there ? 
	int				width;
	int				heigth;
	//mlx components
	void			*pan;
	void			*win;
	void			*img;
	int				*cols;
	//Image parameters
	int				size;
	int				bpp;
	int				endian;
	//array of coordinates/altitudes
	t_pixel			**proj;
	t_pixel			**pixs;
	//Camera options
	int				zoom;
	double			angle_x;
	double			angle_y;
}					t_mlx;

typedef struct		s_param
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				d;
	int				error;
}					t_param;

t_pixel			**read_file(char *fpath, int width, int heigth);
int				get_dim(char *fpath, int *width, int *heigth);
t_pixel			**to_pixel(int fd, int width, int height);
void			del_str_array(char **pixels);
void			del_pixels(t_pixel **pixels, int size);
void			fill_pixels_row(t_pixel *pix, int r, int width, char **s);
void			disp(char **s);


int		clone_pixels(t_mlx *mlx);
t_mlx	*mlx_new(char *arg);
void	ft_puterror(int err);
void	draw_line(t_mlx *mlx, t_pixel p1, t_pixel p2);
void	draw_map(t_mlx *mlx);

#endif
