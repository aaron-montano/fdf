/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:39:16 by amontano          #+#    #+#             */
/*   Updated: 2018/04/23 15:42:54 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ch;
	unsigned char	a;
	int				i;

	i = 0;
	a = (unsigned char)c;
	ch = (unsigned char *)s;
	while (n--)
	{
		if (ch[i] == a)
			return (ch + i);
		i++;
	}
	return (NULL);
}
