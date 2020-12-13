/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molivier <molivier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:31:27 by molivier          #+#    #+#             */
/*   Updated: 2020/12/06 22:04:17 by molivier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*prev;

	node = *lst;
	while (node)
	{
		prev = node;
		node = node->next;
		ft_lstdelone(prev, del);
	}
	*lst = NULL;
}
