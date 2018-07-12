/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 22:46:16 by amontano          #+#    #+#             */
/*   Updated: 2018/07/10 03:39:41 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	if (y < 0)
		return (0);
	if (button >= 0x04 && button <= 0x07)
		translate(button, mlx->view);
	mlx->mouse->isdown |= 1 << button;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse->isdown &= ~(1 << button);
	return (0);
}

int		hook_mousemove(int x, int y, t_mlx *mlx)
{
	mlx->mouse->lastx = mlx->mouse->x;
	mlx->mouse->lasty = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->isdown & (1 << 1) && mlx->mouse->isdown & (1 << 2))
	{
		mlx->view->x += (x - mlx->mouse->lastx);
		mlx->view->y += (y - mlx->mouse->lasty);
	}
	else if (mlx->mouse->isdown & (1 << 1))
	{
		mlx->view->x += (mlx->mouse->lasty - y) / 200.0;
		mlx->view->y -= (mlx->mouse->lastx - x) / 200.0;
	}
	else if (mlx->mouse->isdown & (1 << 2))
	{
		mlx->view->context += (mlx->mouse->lasty - y) / 10.0 + 0.5;
		if (mlx->view->context < 1)
			mlx->view->context = 1;
	}
	if (mlx->mouse->isdown)
		rend(mlx);
	return (0);
}
