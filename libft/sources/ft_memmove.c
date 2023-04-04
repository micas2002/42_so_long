/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:37:46 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/01 11:45:55 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	x;
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)dst;
	ptr2 = (char *)src;
	if (ptr1 < ptr2)
	{
		x = 0;
		while (x < len)
		{
			ptr1[x] = ptr2[x];
			x++;
		}
	}
	else if (ptr1 > ptr2)
	{
		x = len;
		while (x > 0)
		{
			ptr1[x - 1] = ptr2[x - 1];
			x--;
		}
	}
	return (dst);
}
