/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 07:44:52 by amontano          #+#    #+#             */
/*   Updated: 2018/07/10 06:37:50 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		div_lerp(double val, double a, double b)
{
	if (val == a)
		return (0.0);
	if (val == b)
		return (1.0);
	return ((val - a) / (b - a));
}

double		lerp(double a, double b, double pct)
{
	if (a == b)
		return (a);
	return ((b - a) * pct + a);
}

int			color_lerp(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (p == 0.0 || c1 == c2)
		return (c1);
	if (p == 1.0)
		return (c2);
	r = lerp((c1 >> 16), (c2 >> 16), p);
	g = lerp((c1 >> 8), (c2 >> 8), p);
	b = lerp(c1, c2, p);
	return (r << 16 | g << 8 | b);
}
