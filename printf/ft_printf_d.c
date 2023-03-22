/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:23 by mibernar          #+#    #+#             */
/*   Updated: 2022/01/26 17:18:38 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_d(int args)
{
	char	*str;
	int		size;

	str = ft_itoa(args);
	size = ft_strlen(str);
	write(1, str, size);
	free (str);
	return (size);
}
