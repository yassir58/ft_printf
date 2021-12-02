/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:51 by yelatman          #+#    #+#             */
/*   Updated: 2021/11/30 14:10:13 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	handle_null(void)
{
	ft_putstr_fd("(null)", STDOUT);
	return (6);
}

void	handle_format(va_list args,	char c, int *length_ptr)
{
	char	*temp;

	if (c == 'i' || c == 'd')
		*length_ptr += add_print_nbr(va_arg(args, int));
	else if (c == 'c')
		*length_ptr += add_print_char(va_arg(args, int));
	else if (c == 's')
	{
		temp = va_arg(args, char *);
		if (temp)
		*length_ptr += add_print_str(temp);
		else
			*length_ptr += handle_null();
	}
	else if (c == 'u')
		*length_ptr += print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		*length_ptr += print_hex(va_arg(args, unsigned int), c);
	else if (c == 'X')
		*length_ptr += print_hex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		*length_ptr += print_pointer(va_arg(args, unsigned long));
	else if (c == '%')
		*length_ptr += write(STDOUT, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		c_count;

	va_start(args, str);
	i = 0;
	c_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			handle_format(args, str[++i], &c_count);
		}
		else
		{
			ft_putchar_fd(str[i], STDOUT);
			c_count++ ;
		}
		i++;
	}
	return (c_count);
}
