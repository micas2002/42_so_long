/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:02:10 by mibernar          #+#    #+#             */
/*   Updated: 2022/04/21 11:34:17 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	open_format_type(char format_type, va_list args)
{
	int		size;

	size = 0;
	if (format_type == 'c')
		size = ft_printf_c(va_arg(args, int));
	else if (format_type == 'd')
		size = ft_printf_d(va_arg(args, int));
	else if (format_type == 'i')
		size = ft_printf_i(va_arg(args, int));
	else if (format_type == 'p')
		size = ft_printf_p(va_arg(args, void *));
	else if (format_type == 's')
		size = ft_printf_s(va_arg(args, char *));
	else if (format_type == 'u')
		size = ft_printf_u(va_arg(args, int));
	else if (format_type == 'x')
		size = ft_printf_x_lower(va_arg(args, int));
	else if (format_type == 'X')
		size = ft_printf_x_upper(va_arg(args, int));
	return (size);
}

int	check_format(char *format, int x)
{
	if (format[x] == 'c' || format[x] == 's' || format[x] == 'p'
		|| format[x] == 'd' || format[x] == 'i' || format[x] == 'u'
		|| format[x] == 'x' || format[x] == 'X')
		return (1);
	return (0);
}

int	size_counter(char *format, int x, int size, va_list args)
{
	char	format_type;

	if (format[x] != '%' && check_format(format, x) == 1)
	{
		format_type = format[x];
		size += open_format_type(format_type, args);
	}
	else
	{
		ft_putchar_fd(format[x], 1);
		size++;
	}
	return (size);
}

int	treat_format(char *format, va_list args)
{
	int		size;
	int		x;
	int		loop;

	size = 0;
	x = 0;
	loop = 0;
	while (format[x] != '\0')
	{
		if (format[x] == '%' && format[x + 1])
		{
			x++;
			loop++;
			size = size_counter(format, x, size, args);
		}
		else
			ft_putchar_fd(format[x], 1);
		x++;
		size++;
	}
	va_end(args);
	return (size - loop);
}

int	ft_printf(const char *format, ...)
{
	int		x;
	char	*temp;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	temp = ft_strdup(format);
	x = treat_format(temp, args);
	free (temp);
	return (x);
}
