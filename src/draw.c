/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 06:50:49 by amontano          #+#    #+#             */
/*   Updated: 2018/07/10 08:06:37 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_points(t_mlx *mlx, t_line *l, t_vect *v1, t_vect *v2)
{
	double	pct;

	if (v1->x < 0 || v1->x >= WIN_W || v1->y < 0 || v1->y >= WIN_H \
		|| v2->x < 0 || v2->x >= WIN_W || v2->y < 0 || v2->y >= WIN_H)
		return (1);
	pct = (l->dx > l->dy ? \
			div_lerp((int)v1->x, (int)l->begin.x, (int)l->end.x) \
			: div_lerp((int)v1->y, (int)l->begin.y, (int)l->end.y));
	img_set_pixel(mlx->img, (int)v1->x, (int)v1->y, \
			color_lerp(v1->color, v2->color, pct));
	l->err2 = l->err;
	if (l->err2 > -l->dx)
	{
		l->err -= l->dy;
		v1->x += l->sx;
	}
	if (l->err2 < l->dy)
	{
		l->err += l->dx;
		v1->y += l->sy;
	}
	return (0);
}

static void	set_ln(t_mlx *mlx, t_vect pa, t_vect pb)
{
	t_line	line;

	pa.x = (int)pa.x;
	pa.y = (int)pa.y;
	pb.x = (int)pb.x;
	pb.y = (int)pb.y;
	line.begin = pa;
	line.end = pb;
	line.dx = (int)ft_abs((int)pb.x - (int)pa.x);
	line.sx = (int)pa.x < (int)pb.x ? 1 : -1;
	line.dy = (int)ft_abs((int)pb.y - (int)pa.y);
	line.sy = (int)pa.y < (int)pb.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (((int)pa.x != (int)pb.x || (int)pa.y != (int)pb.y))
		if (get_points(mlx, &line, &pa, &pb))
			break ;
}

t_vect		rotate(t_vect p, t_view *r)
{
	t_vect	v;
	double	x;
	double	y;
	double	z;

	x = p.x;
	y = p.y;
	v.x = cos(r->z) * x - sin(r->z) * y;
	v.y = sin(r->z) * x + cos(r->z) * y;
	x = v.x;
	z = p.z;
	v.x = cos(r->y) * x + sin(r->y) * z;
	v.z = -sin(r->y) * x + cos(r->y) * z;
	y = v.y;
	z = v.z;
	v.y = cos(r->x) * y - sin(r->x) * z;
	v.z = sin(r->x) * y + cos(r->x) * z;
	v.color = p.color;
	return (v);
}

t_vect		pvect(t_vect v, t_mlx *mlx)
{
	v.x -= (double)(mlx->map->width - 1) / 2.0;
	v.y -= (double)(mlx->map->height - 1) / 2.0;
	v.z -= (double)(mlx->map->dep_min + mlx->map->dep_max) / 2.0;
	v = rotate(v, mlx->view);
	v.x *= mlx->view->context;
	v.y *= mlx->view->context;
	v.z *= mlx->view->context;
	v.x += mlx->view->x_off;
	v.y += mlx->view->y_off;
	return (v);
}

int			rend(t_mlx *mlx)
{
	int			x;
	int			y;
	t_vect		v;
	t_map		*map;

	map = mlx->map;
	clear_img(mlx->img);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			v = pvect(vect_at(map, x, y), mlx);
			if (x + 1 < map->width)
				set_ln(mlx, v, pvect(vect_at(map, x + 1, y), mlx));
			if (y + 1 < map->height)
				set_ln(mlx, v, pvect(vect_at(map, x, y + 1), mlx));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	return (0);
}
