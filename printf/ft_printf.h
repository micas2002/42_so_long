/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:04:18 by mibernar          #+#    #+#             */
/*   Updated: 2022/02/02 12:32:02 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

// PROTOTYPES

int		ft_printf(const char *format, ...);
int		ft_printf_c(int args);
int		ft_printf_i(int args);
int		ft_printf_d(int args);
int		ft_printf_p(void *args);
int		ft_printf_s(char *args);
int		ft_printf_u(int args);
int		ft_printf_x_lower(int args);
int		ft_printf_x_upper(int args);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	ft_putchar_fd(char c, int fd);
char	*ft_unsigned_itoa(unsigned int n);

#endif
