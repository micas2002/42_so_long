/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:12:23 by mibernar          #+#    #+#             */
/*   Updated: 2021/10/28 15:02:07 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	int	i;
	int	a;

	a = n;
	i = 0;
	while (i < a)
	{
		*(unsigned char *)(b + i) = c;
		i++;
	}
	return (b);
}
