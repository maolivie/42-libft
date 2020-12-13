/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molivier <molivier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 02:50:23 by molivier          #+#    #+#             */
/*   Updated: 2020/12/06 21:15:20 by molivier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*dst;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dst = malloc(sizeof(char) * len);
	if (dst == NULL)
		return (NULL);
	return ((char *)ft_memcpy(dst, s1, len));
}
