/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:00:56 by mibernar          #+#    #+#             */
/*   Updated: 2021/10/28 15:01:36 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				x;
	unsigned char		*ptr;

	x = 0;
	ptr = (unsigned char *)s;
	while (x < n)
	{
		if (ptr[x] == (unsigned char)c)
		{
			return (&ptr[x]);
		}
		x++;
	}
	return (NULL);
}
