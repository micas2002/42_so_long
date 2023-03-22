/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:06:27 by mibernar          #+#    #+#             */
/*   Updated: 2021/10/28 15:03:35 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (dst[x] && x < dstsize)
		x++;
	y = 0;
	while (src[y] && (x + y + 1) < dstsize)
	{
		dst[x + y] = src[y];
		y++;
	}
	if (x < dstsize)
		dst[x + y] = '\0';
	return (x + ft_strlen(src));
}
