/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:57:23 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/15 11:05:19 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	join(char *str, const char *s1, const char *s2)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s1[x] != '\0')
	{
		str[x] = s1[x];
		x++;
	}
	while (s2[y] != '\0')
	{
		str[x] = s2[y];
		x++;
		y++;
	}
	str[x] = '\0';
	return (*str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)(s1)) + ft_strlen((char *)(s2)) + 1));
	if (!str)
		return (NULL);
	join(str, s1, s2);
	return (str);
}
