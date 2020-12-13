/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molivier <molivier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 01:08:35 by molivier          #+#    #+#             */
/*   Updated: 2020/12/10 06:47:28 by molivier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void			*ft_freetab(char **tab, size_t i)
{
	while (i-- > 0)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static char const	*ft_skipsep(char const *s, char c)
{
	while (*s && *s == c)
		++s;
	return (s);
}

static char const	*ft_skipword(char const *s, char c)
{
	while (*s && *s != c)
		++s;
	return (s);
}

static size_t		ft_countwords(char const *s, char c)
{
	size_t	count;

	count = 0;
	s = ft_skipsep(s, c);
	while (*s)
	{
		s = ft_skipword(s, c);
		s = ft_skipsep(s, c);
		++count;
	}
	return (count);
}

char				**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;
	size_t	i;

	words = ft_countwords(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		s = ft_skipsep(s, c);
		tab[i] = ft_substr(s, 0, ft_skipword(s, c) - s);
		if (tab[i] == NULL)
			return ((char **)ft_freetab(tab, i));
		s = ft_skipword(s, c);
		++i;
	}
	tab[i] = NULL;
	return (tab);
}
