/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molivier <molivier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:40:36 by molivier          #+#    #+#             */
/*   Updated: 2020/12/06 21:12:56 by molivier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;
	size_t				i;

	if (n == 0)
		return (0);
	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	i = 0;
	while (a[i] == b[i] && i + 1 < n)
		++i;
	return (a[i] - b[i]);
}
