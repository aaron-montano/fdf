/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:09:13 by amontano          #+#    #+#             */
/*   Updated: 2018/07/10 04:34:22 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate(int key, t_view *v)
{
	if (key == ARROW_L || key == SCR_L)
		v->x_off -= 8;
	else if (key == ARROW_R || key == SCR_R)
		v->x_off += 8;
	else if (key == ARROW_U || key == SCR_U)
		v->y_off -= 8;
	else if (key == ARROW_D || key == SCR_D)
		v->y_off += 8;
}

void	rotate_img(int key, t_view *v)
{
	if (key == KEY_Q)
		v->z -= M_PI / 180 * v->rot_speed;
	v->z = fmod(v->z, 360);
	if (key == KEY_E)
		v->z += M_PI / 180 * v->rot_speed;
	v->z = fmod(v->z, 360);
	if (key == KEY_W)
		v->x += M_PI / 180 * v->rot_speed;
	v->x = fmod(v->x, 360);
	if (key == KEY_S)
		v->x -= M_PI / 180 * v->rot_speed;
	v->x = fmod(v->x, 360);
	if (key == KEY_A)
		v->y -= M_PI / 180 * v->rot_speed;
	v->y = fmod(v->y, 360);
	if (key == KEY_D)
		v->y += M_PI / 180 * v->rot_speed;
	v->y = fmod(v->y, 360);
}

void	roll(int key, t_view *v)
{
	if (key == 0x26)
	{
		v->x -= M_PI / 180 * v->rot_speed;
		v->x = fmod(v->x, 360);
		v->x_off -= 4 + (v->rot_speed / 5);
	}
	if (key == 0x25)
	{
		v->x += M_PI / 180 * v->rot_speed;
		v->x = fmod(v->x, 360);
		v->x_off += 4 + (v->rot_speed / 5);
	}
	if (key == 0x22)
	{
		v->z -= M_PI / 180 * v->rot_speed;
		v->y_off -= 4 + (v->rot_speed / 5);
	}
	if (key == 0x28)
	{
		v->z += M_PI / 180 * v->rot_speed;
		v->y_off += 4 + (v->rot_speed / 5);
	}
}

void	set_color_scheme(int key, t_map *m)
{
	if (key == 0x12)
		m->color_min = 0xFF0000;
	if (key == 0x13)
		m->color_min = 0x00AB00;
	if (key == 0x14)
		m->color_min = 0x0000FF;
	if (key == 0x15)
		m->color_min = 0xAAB209;
	if (key == 0x16)
		m->color_min = 0x0A0A0A;
	fill_color(m);
}

void	restore_defaults(t_view *v)
{
	v->x = 0.0;
	v->y = 0.0;
	v->z = 0.0;
	v->x_off = WIN_W / 2;
	v->y_off = WIN_H / 2;
	v->rot_speed = 1;
	v->context = WIN_H / 20;
}
