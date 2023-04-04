/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:57:05 by mibernar          #+#    #+#             */
/*   Updated: 2022/06/24 11:59:54 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		x;
	int		y;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	x = 0;
	y = 0;
	while (s1 && s1[x] != '\0')
	{
		str[x] = s1[x];
		x++;
	}
	while (s2 && s2[y] != '\0')
	{
		str[x] = s2[y];
		x++;
		y++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_strdup_gnl(char *s1)
{
	char	*dest;
	int		x;

	if (s1[0] == '\0')
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	x = 0;
	while (s1[x] != '\0')
	{
		dest[x] = s1[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

int	ft_strchr_gnl(char *temp, int c)
{
	int	i;

	if (!temp)
		return (0);
	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == c)
			return (1);
		i++;
	}
	if (temp[i] == 0 && c != 0)
		return (0);
	return (0);
}
