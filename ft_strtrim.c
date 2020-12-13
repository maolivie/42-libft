/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molivier <molivier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 22:35:35 by molivier          #+#    #+#             */
/*   Updated: 2020/12/06 21:18:20 by molivier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	size_t	end;

	size = ft_strlen(set);
	while (ft_memchr(set, *s1, size))
		++s1;
	end = ft_strlen(s1);
	while (ft_memchr(set, s1[end], size + 1) && end > 0)
		--end;
	return (ft_substr(s1, 0, end + 1));
}
