/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molivier <molivier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:25:10 by molivier          #+#    #+#             */
/*   Updated: 2020/12/06 21:13:35 by molivier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (dst > src)
	{
		s = (const unsigned char *)src;
		d = (unsigned char *)dst;
		while (len-- > 0)
			d[len] = s[len];
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
