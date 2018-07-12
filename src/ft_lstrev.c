/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 21:11:41 by amontano          #+#    #+#             */
/*   Updated: 2018/06/26 04:55:15 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*prv;
	t_list	*cur;
	t_list	*nxt;

	prv = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		nxt = cur->next;
		cur->next = prv;
		prv = cur;
		cur = nxt;
	}
	*alst = prv;
}
