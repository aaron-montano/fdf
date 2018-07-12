/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 06:26:02 by amontano          #+#    #+#             */
/*   Updated: 2018/07/10 06:40:46 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		uldispose(char ***split)
{
	char	**str;
	int		i;

	i = 0;
	str = &(*split)[i];
	while (*str)
	{
		ft_strdel(str);
		i++;
		str = &(*split)[i];
	}
	ft_memdel((void **)split);
	return (0);
}

int		dispose(t_list **lst, t_map **map)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_memdel(&(*lst)->content);
		ft_memdel((void **)lst);
		*lst = next;
	}
	if (map && *map)
	{
		ft_memdel((void **)&(*map)->vect);
		ft_memdel((void **)map);
	}
	return (0);
}

void	fill_color(t_map *m)
{
	t_vect	v;
	t_vect	*cur;

	v.y = 0;
	while (v.y < m->height)
	{
		v.x = 0;
		while (v.x < m->width)
		{
			cur = m->vect[(int)v.y * m->width + (int)v.x];
			cur->color = color_lerp(m->color_min, m->color_max, \
				div_lerp(cur->z, m->dep_min, m->dep_max));
			v.x++;
		}
		v.y++;
	}
}

void	set_depth(t_map *m)
{
	int		min;
	int		max;
	t_vect	v;
	t_vect	cursor;

	min = INT_MAX;
	max = INT_MIN;
	v.y = 0;
	while (v.y < m->height)
	{
		v.x = 0;
		while (v.x < m->width)
		{
			cursor = *m->vect[(int)v.y * m->width + (int)v.x];
			min = cursor.z < min ? cursor.z : min;
			max = cursor.z > max ? cursor.z : max;
			v.x++;
		}
		v.y++;
	}
	m->dep_min = min;
	m->dep_max = max;
}

t_vect	vect_at(t_map *map, int x, int y)
{
	return (*map->vect[y * map->width + x]);
}
