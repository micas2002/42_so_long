/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:07:57 by mibernar          #+#    #+#             */
/*   Updated: 2021/10/28 15:03:57 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	x;

	x = 0;
	if (n == 0)
	{
		return (0);
	}
	while ((unsigned char)s1[x] == (unsigned char)s2[x]
		&& ((unsigned char)s1[x] != '\0'
			&& (unsigned char)s2[x] != '\0' ) && x < n - 1)
	{
		x++;
	}
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
