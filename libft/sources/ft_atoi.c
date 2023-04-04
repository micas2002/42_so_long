/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:54:25 by mibernar          #+#    #+#             */
/*   Updated: 2021/11/11 12:37:18 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	x;
	int	a;
	int	sinal;

	sinal = 1;
	a = 0;
	x = 0;
	while (str[x] != '\0' && (str[x] == ' ' || str[x] == 12
			|| str[x] == 10 || str[x] == 13 || str[x] == 9 || str[x] == 11))
		x++;
	while (str[x] != '\0' && (str[x] == 43 || str[x] == 45))
	{
		if (str[x + 1] == '+' || str[x + 1] == '-')
			return (0);
		else if (str[x] == '-')
			sinal *= -1;
		x++;
	}
	while (str[x] > 47 && str[x] < 58)
	{
		a = (str[x] - '0') + (a * 10);
		x++;
	}
	return (a * sinal);
}
