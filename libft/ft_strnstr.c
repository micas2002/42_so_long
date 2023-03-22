/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:57:28 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/16 13:51:45 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	i;

	x = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[x] != '\0' && x < len)
	{
		if (haystack[x] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[x + i] == needle[i]
				&& (size_t)(x + i) < len)
				++i;
			if (needle[i] == '\0')
				return ((char *) &haystack[x]);
		}
		x++;
	}
	return (NULL);
}
