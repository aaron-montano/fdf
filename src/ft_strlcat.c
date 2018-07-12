/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:57:02 by amontano          #+#    #+#             */
/*   Updated: 2018/04/25 00:28:45 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (size < ft_strlen((char const *)dst))
		dstlen = size;
	else
		dstlen = ft_strlen((char const *)dst);
	if (size == dstlen)
		return (srclen + size);
	if (srclen < size - dstlen)
		ft_strncat(dst, src, srclen + 1);
	else
	{
		ft_strncat(dst, src, size - dstlen - 1);
		dst[size - 1] = '\0';
	}
	return (dstlen + srclen);
}
