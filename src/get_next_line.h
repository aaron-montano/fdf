/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:26:43 by amontano          #+#    #+#             */
/*   Updated: 2018/06/22 17:09:10 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 42
# define IF_NULL_RZERO(a) if (!a) return (0);

typedef struct	s_gnl
{
	int				fd;
	char			*line;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(const int fd, char **line);
#endif
