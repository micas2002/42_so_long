/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:33 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/31 11:35:32 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*rev_str(char *hex_num)
{
	char	*temp;
	int		x;
	int		y;

	x = ft_strlen(hex_num);
	temp = malloc(sizeof(char) * x + 1);
	y = 0;
	x -= 1;
	while (hex_num && x >= 0)
	{
		temp[y] = hex_num[x];
		x--;
		y++;
	}
	temp[y] = '\0';
	return (temp);
}

static char	*convert(long quotient, char *hex_num)
{
	int		j;
	long	remainder;

	j = 0;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hex_num[j++] = 48 + remainder;
		else
			hex_num[j++] = 55 + remainder;
		quotient = quotient / 16;
	}
	hex_num[j] = '\0';
	return (hex_num);
}

int	ft_printf_x_upper(int args)
{
	long	quotient;
	int		i;
	char	*hex_num;
	char	*final;

	if (args < 0)
		quotient = 4294967296 + args;
	else if (args == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
		quotient = args;
	hex_num = malloc(sizeof(char) * 500);
	final = convert(quotient, hex_num);
	final = rev_str(final);
	i = ft_strlen(final);
	write (1, final, i);
	free (hex_num);
	free (final);
	return (i);
}
