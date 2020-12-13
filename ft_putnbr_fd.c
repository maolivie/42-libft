/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molivier <molivier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:07:42 by molivier          #+#    #+#             */
/*   Updated: 2020/12/06 16:19:24 by molivier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		abs = -n;
	}
	else
		abs = n;
	if (abs >= 10)
		ft_putnbr_fd(abs / 10, fd);
	ft_putchar_fd(abs % 10 + '0', fd);
}
