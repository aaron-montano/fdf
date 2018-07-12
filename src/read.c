/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 04:30:55 by amontano          #+#    #+#             */
/*   Updated: 2018/07/10 07:25:06 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vect			*set_vect(int x, int y, char *str)
{
	t_vect	*v;

	v = ft_memalloc(sizeof(t_vect));
	if (v == NULL)
		return (NULL);
	v->x = (double)x;
	v->y = (double)y;
	v->z = (double)ft_atoi(str);
	v->color = 0xFF0000;
	return (v);
}

static int		fill_map(t_map **m, t_list *list)
{
	t_list		*cursor;
	char		**split;
	int			x;
	int			y;

	cursor = list;
	y = 0;
	while (y < (*m)->height)
	{
		x = 0;
		if ((split = ft_strsplit(cursor->content, ' ')) == NULL)
			return (dispose(&list, m));
		while (x < (*m)->width)
		{
			(*m)->vect[y * (*m)->width + x] = set_vect(x, y, split[x]);
			x++;
		}
		uldispose(&split);
		cursor = cursor->next;
		y++;
	}
	set_depth(*m);
	fill_color(*m);
	dispose(&list, NULL);
	return (1);
}

static t_map	*gen_map(int width, int height)
{
	t_map *map;

	map = ft_memalloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = width;
	map->height = height;
	map->dep_max = 0;
	map->dep_min = 0;
	map->color_min = 0x0000FF;
	map->color_max = 0x00FF00;
	map->vect = ft_memalloc(sizeof(t_vect *) * width * height);
	if (!(map->vect))
	{
		ft_memdel((void **)&map);
		return (NULL);
	}
	return (map);
}

static int		get_lines(int fd, t_list **lst)
{
	t_list	*tmp;
	int		fin;
	int		ret;
	char	*line;

	fin = -1;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (fin == -1)
			fin = ft_wordcount_d(line, ' ');
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		if ((tmp) == NULL)
			return (dispose(lst, NULL));
		ft_listaddend(lst, tmp);
		if (fin != ft_wordcount_d(line, ' '))
			return (dispose(lst, NULL));
		ft_strdel(&line);
	}
	if (fin == -1 || ret == -1)
		return (dispose(lst, NULL));
	return (1);
}

int				read_file(int fd, t_map **map)
{
	t_list	*lst;

	lst = NULL;
	if (!(get_lines(fd, &lst)))
		return (0);
	*map = gen_map((int)ft_wordcount_d(lst->content, ' '),
			(int)ft_lstcount(lst));
	if (*map == NULL)
		return (dispose(&lst, map));
	return (fill_map(map, lst));
}
