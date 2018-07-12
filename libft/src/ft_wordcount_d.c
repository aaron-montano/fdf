/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 22:38:54 by amontano          #+#    #+#             */
/*   Updated: 2018/07/02 04:29:10 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount_d(char *str, char delimit)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i] && str[i] == delimit)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != delimit)
			i++;
		res++;
		while (str[i] && str[i] == delimit)
			i++;
	}
	return (res);
}
