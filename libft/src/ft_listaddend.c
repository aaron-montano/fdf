/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listaddend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 02:25:41 by amontano          #+#    #+#             */
/*   Updated: 2018/07/10 07:21:45 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_listaddend(t_list **alst, t_list *new)
{
	t_list *i;

	i = *alst;
	if (i == NULL)
	{
		*alst = new;
		return ;
	}
	while (i->next != NULL)
		i = i->next;
	i->next = new;
}
