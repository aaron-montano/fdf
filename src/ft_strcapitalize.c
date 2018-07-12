/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 00:34:02 by amontano          #+#    #+#             */
/*   Updated: 2018/04/26 01:17:43 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (ft_islower(str[i]) == 1)
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
		while (ft_isprint(str[i]) == 1 && ft_iswhitespace(str[i]) == 0)
			i++;
		while (ft_iswhitespace(str[i]) == 1)
			i++;
	}
	return (str);
}
