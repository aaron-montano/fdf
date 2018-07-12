/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 22:52:37 by amontano          #+#    #+#             */
/*   Updated: 2018/07/10 04:32:26 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	hook_keydown(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	if (key == 0x45)
	{
		mlx->view->rot_speed = mlx->view->rot_speed == 1 ? 0 :
			mlx->view->rot_speed;
		mlx->view->rot_speed += 15;
		mlx->view->rot_speed %= 360;
	}
	if (key == 0x4E)
	{
		mlx->view->rot_speed -= 15;
		mlx->view->rot_speed = mlx->view->rot_speed < 1 ? 1 :
			mlx->view->rot_speed;
		mlx->view->rot_speed %= 360;
	}
	if (key >= 0x12 && key <= 0x16)
		set_color_scheme(key, mlx->map);
	return (0);
}

int	hook_key_pressed(int key, t_mlx *mlx)
{
	if (key >= ARROW_L && key <= ARROW_U)
		translate(key, mlx->view);
	if ((key >= KEY_A && key <= KEY_D) \
		|| (key >= KEY_Q && key <= KEY_E))
		rotate_img(key, mlx->view);
	if (key == 0x22 || key == 0x26 || key == 0x28 || key == 0x25)
		roll(key, mlx->view);
	if (key == KEY_Z)
	{
		mlx->view->context -= 1;
		mlx->view->context = mlx->view->context < 1 ? 1 : mlx->view->context;
	}
	if (key == KEY_X)
		mlx->view->context += 1;
	if (key == 42)
		restore_defaults(mlx->view);
	return (0);
}
