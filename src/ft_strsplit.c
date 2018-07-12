/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 22:38:51 by amontano          #+#    #+#             */
/*   Updated: 2018/07/06 21:24:26 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char		*next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static void		cleanup(char **split, size_t cur)
{
	while (cur > 0)
	{
		cur--;
		ft_strdel(&split[cur]);
	}
	ft_strdel(split);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	cur;
	size_t	wordcount;

	wordcount = ft_wordcount_d((char *)s, c);
	split = (char **)ft_memalloc((wordcount + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	cur = 0;
	while (cur < wordcount)
	{
		s = next_word(s, c);
		split[cur] = ft_strsub(s, 0, word_len(s, c));
		if (split[cur] == NULL)
		{
			cleanup(split, cur);
			return (NULL);
		}
		cur++;
		s += word_len(s, c);
	}
	split[wordcount] = NULL;
	return (split);
}
