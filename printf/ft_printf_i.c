/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:05:12 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/26 17:18:59 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_hex_to_dec(int i, int decimal, int base, char *hex)
{
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			decimal += (hex[i] - 48) * base;
			base *= 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			decimal += (hex[i] - 55) * base;
			base *= 16;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			decimal += (hex[i] - 87) * base;
			base *= 16;
		}
		i--;
	}
	return (decimal);
}

int	ft_hexadecimal(char *hex)
{
	int		i;
	int		decimal;
	int		base;
	char	*str;

	decimal = 0;
	base = 1;
	i = ft_strlen(hex);
	decimal = convert_hex_to_dec(i, decimal, base, hex);
	str = ft_itoa(decimal);
	write (1, str, i);
	free (str);
	return (i);
}

int	ft_octal(int n)
{
	int		size;
	int		decimal;
	int		r;
	int		octal;
	char	*str;

	octal = 1;
	decimal = 0;
	while (n > 0)
	{
		r = n % 10;
		n = n / 10;
		octal *= 8;
		decimal = decimal + r * octal;
	}
	str = ft_itoa(decimal);
	size = ft_strlen(str);
	write (1, str, size);
	return (size);
}

int	ft_printf_i(int args)
{
	int		a;
	int		size;
	char	*str;

	a = args;
	str = ft_itoa(a);
	if (str[0] == 30)
	{
		if (str[1] == 'x' || str[1] == 'X')
			size = ft_hexadecimal(str);
		else
			size = ft_octal(a);
		free (str);
		return (size);
	}
	size = ft_strlen(str);
	write (1, str, size);
	free (str);
	return (size);
}
