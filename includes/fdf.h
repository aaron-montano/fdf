/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 04:08:30 by amontano          #+#    #+#             */
/*   Updated: 2018/07/11 01:21:02 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# define WIN_H 		900
# define WIN_W 		1440

# define KEY_W 		0x0D
# define KEY_A		0x00
# define KEY_S		0x01
# define KEY_D		0x02
# define KEY_Q		0x0C
# define KEY_E		0x0E
# define KEY_Z		0x06
# define KEY_X		0x07
# define KEY_ESC	0x35
# define ARROW_L	0x7B
# define ARROW_R	0x7C
# define ARROW_U	0x7E
# define ARROW_D	0x7D
# define SCR_L		0x06
# define SCR_R		0x07
# define SCR_U		0x04
# define SCR_D		0x05

typedef struct	s_img
{
	void		*img;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}				t_img;

typedef struct	s_view
{
	double		x_off;
	double		y_off;
	double		x;
	double		y;
	double		z;
	int			context;
	int			rot_speed;
}				t_view;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_vect;

typedef struct	s_map
{
	int			width;
	int			height;
	int			dep_min;
	int			dep_max;
	int			color_min;
	int			color_max;
	t_vect		**vect;
}				t_map;

typedef struct	s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}				t_mouse;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_view		*view;
	t_mouse		*mouse;
}				t_mlx;

typedef struct	s_line
{
	t_vect		begin;
	t_vect		end;
	int			dy;
	int			dx;
	int			sy;
	int			sx;
	int			err;
	int			err2;
}				t_line;

/*
** draw.c
*/
int				rend(t_mlx *mlx);
/*
** img.c
*/
t_img			*new_img(t_mlx *mlx);
void			img_set_pixel(t_img *img, int x, int y, int color);
t_img			*del_img(t_mlx *mlx, t_img *img);
void			clear_img(t_img *img);
/*
** interpolate.c
*/
double			div_lerp(double d, double a, double b);
int				color_lerp(int c1, int c2, double p);
/*
** read.c
*/
int				read_file(int fd, t_map **map);
/*
** transform.c
*/
void			rotate_img(int key, t_view *v);
void			translate(int key, t_view *v);
void			restore_defaults(t_view *v);
void			roll(int key, t_view *v);
void			set_color_scheme(int key, t_map *m);
/*
** util.c
*/
int				uldispose(char	***split);
int				dispose(t_list **lst, t_map **map);
void			set_depth(t_map *m);
t_vect			vect_at(t_map*map, int x, int y);
void			fill_color(t_map *m);
/*
** mouse.c
*/
int				hook_mousedown(int button, int x, int y, t_mlx *mlx);
int				hook_mouseup(int button, int x, int y, t_mlx *mlx);
int				hook_mousemove(int x, int y, t_mlx *mlx);
/*
** keyboard.c
*/
int				hook_keydown(int key, t_mlx *mlx);
int				hook_key_pressed(int key, t_mlx *mlx);
#endif
