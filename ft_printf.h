/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:30:53 by yelatman          #+#    #+#             */
/*   Updated: 2021/11/17 18:55:25 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define STDOUT 1

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		add_print_nbr(int n);
int		add_print_str(char *str);
int		add_print_char(int n);
int		print_unsigned(int n);
int		print_hex(unsigned int n, char c);
int		print_pointer(unsigned long n);
int		convert_base(unsigned int nb, int n);
int		convert_long(unsigned long nb);
void	ft_putchar_fd(char c, int n);
void	ft_putstr_fd(char const *str, int n);
void	ft_putnbr_fd(int n, int nb);
size_t	ft_strlen(char const *str);
#endif
