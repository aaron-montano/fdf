/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 19:16:51 by amontano          #+#    #+#             */
/*   Updated: 2018/06/25 21:02:08 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	set_ptr(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		r;

	if ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	return (r);
}

t_gnl		*start_file(const int fd, t_gnl **s_list)
{
	t_gnl *cur;

	cur = *s_list;
	while (cur && cur->fd != fd)
		cur = cur->next;
	if (!cur)
	{
		cur = (t_gnl *)ft_memalloc(sizeof(t_gnl));
		cur->fd = fd;
		if (!(cur->line = ft_strnew(0)))
			return (NULL);
		cur->next = *s_list;
		*s_list = cur;
	}
	return (cur);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*s_list;
	t_gnl			*a;
	char			*tmp;

	if (fd < 0 || !line)
		return (-1);
	a = start_file(fd, &s_list);
	IF_NULL_RZERO(a->line);
	while (!(ft_strchr(a->line, '\n')))
	{
		if (set_ptr(a->fd, &a->line) < 0)
			return (-1);
		if (!(set_ptr(a->fd, &a->line)) && (!(ft_strchr(a->line, '\n'))))
		{
			IF_NULL_RZERO(a->line[0]);
			*line = a->line;
			a->line = NULL;
			return (1);
		}
	}
	*line = ft_strsub(a->line, 0, (ft_strchr(a->line, '\n') - a->line));
	tmp = a->line;
	a->line = ft_strdup(ft_strchr(a->line, '\n') + 1);
	ft_strdel(&tmp);
	return (1);
}
