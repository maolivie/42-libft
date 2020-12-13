/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molivier <molivier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:42:08 by molivier          #+#    #+#             */
/*   Updated: 2020/12/06 21:11:22 by molivier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		++len;
	while (n >= 10 || n <= -10)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	abs;

	len = ft_nbrlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		abs = -n;
	}
	else
		abs = n;
	str[len--] = '\0';
	while (abs >= 10)
	{
		str[len--] = abs % 10 + '0';
		abs /= 10;
	}
	str[len] = abs + '0';
	return (str);
}
