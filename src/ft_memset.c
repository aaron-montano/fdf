/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:16:22 by amontano          #+#    #+#             */
/*   Updated: 2018/04/25 00:27:30 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ch;

	if (len == 0)
		return (b);
	ch = (unsigned char *)b;
	while (len--)
	{
		*ch = (unsigned char)c;
		if (len)
			ch++;
	}
	return (b);
}
