/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:44:58 by mibernar          #+#    #+#             */
/*   Updated: 2021/10/28 15:03:39 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_size;
	size_t	x;

	src_size = ft_strlen(src);
	x = 0;
	if (dstsize != 0)
	{
		while (src[x] != '\0' && x < (dstsize - 1))
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = '\0';
	}
	return (src_size);
}
