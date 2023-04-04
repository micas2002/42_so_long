/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:14:13 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/04 17:27:15 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*x;

	while (lst && *lst)
	{
		x = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = x;
	}
	lst = NULL;
}
