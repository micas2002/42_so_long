/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:04:51 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/14 17:39:40 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_strcpy(char *dst, const char *src)
{
	unsigned char	x;

	x = 0;
	while (*(src + x) != '\0')
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (*dst);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		x;
	char	*str;

	x = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, s);
	while (str[x])
	{
		str[x] = (*f)(x, str[x]);
		x++;
	}
	return (str);
}
