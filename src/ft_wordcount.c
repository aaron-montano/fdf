/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 00:12:23 by amontano          #+#    #+#             */
/*   Updated: 2018/06/26 01:06:30 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_wordcount(char const *str)
{
	unsigned int	words;
	int				i;

	i = 0;
	words = 0;
	while (str[i] && ft_iswhitespace(str[i]) == 1)
		i++;
	while (str[i])
	{
		while (str[i] && ft_iswhitespace(str[i]) == 0)
			i++;
		words++;
		while (ft_iswhitespace(str[i]) == 1)
			i++;
	}
	return (words);
}
