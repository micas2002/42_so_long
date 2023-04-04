/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:13:08 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/16 13:46:26 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	wrd_count;

	wrd_count = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			wrd_count++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (wrd_count);
}

static int	str_size(char const *s, char c, size_t a)
{
	size_t	i;

	i = a;
	if (s[i] == c)
	{
		while (s[i] == c)
			i++;
	}
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int	trim_size(char const *s, char c, size_t a)
{
	size_t	i;
	size_t	x;

	i = a;
	x = 0;
	if (s[i] == c)
	{
		while (s[i] == c)
			i++;
	}
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (x);
		i++;
		x++;
	}
	return (x);
}

static char	*cpy(char const *s, char *str, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (ft_strlen(s) < len)
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	else if (start > ft_strlen(s))
		str = (char *)malloc(sizeof(char) * 1);
	else
		str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	wrd_number;
	size_t	i;
	size_t	x;
	size_t	a;
	char	**str;

	i = 0;
	a = 0;
	if (!s)
		return (NULL);
	wrd_number = word_count(s, c);
	str = (char **)malloc(sizeof(char *) * (wrd_number + 1));
	if (!str)
		return (NULL);
	while (i < wrd_number)
	{
		x = trim_size(s, c, a);
		a = str_size(s, c, a);
		str[i] = cpy(s, *str, (unsigned int)(a - x), x);
		i++;
	}
	str[i] = NULL;
	return (str);
}
