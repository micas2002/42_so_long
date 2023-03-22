/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:39:08 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/21 11:22:15 by miguel           ###   ########.fr       */
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

static char	*convert(unsigned long quotient, char *hex_num)
{
	int				j;
	unsigned long	remainder;

	j = 0;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hex_num[j++] = 48 + remainder;
		else
			hex_num[j++] = 87 + remainder;
		quotient = quotient / 16;
	}
	hex_num[j] = '\0';
	return (hex_num);
}

char	*hexa_convert(long args)
{
	unsigned long	quotient;
	char			*hex_num;
	char			*final;

	if (args < 0)
		quotient = 4294967296 + args;
	else if (args == 0)
	{
		final = malloc(sizeof(char) * 1);
		final[0] = '0';
		final[1] = '\0';
		return (final);
	}
	else
		quotient = args;
	hex_num = malloc(sizeof(char) * 500);
	final = convert(quotient, hex_num);
	final = rev_str(final);
	free (hex_num);
	return (final);
}

int	ft_printf_p(void *args)
{
	unsigned long	address;
	size_t			size;
	char			*str;

	address = (unsigned long) args;
	str = hexa_convert(address);
	size = ft_strlen(str);
	write(1, "0x", 2);
	write(1, str, size);
	free(str);
	return (size + 2);
}
