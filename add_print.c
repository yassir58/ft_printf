/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:07:33 by yelatman          #+#    #+#             */
/*   Updated: 2021/11/19 21:28:47 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	count_size(int nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr != 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

int	add_print_nbr(int nbr)
{
	int	res;

	res = 0;
	res = count_size(nbr);
	ft_putnbr_fd(nbr, STDOUT);
	return (res);
}

int	add_print_str(char *str)
{
	int	res ;

	res = 0;
	ft_putstr_fd(str, STDOUT);
	res = ft_strlen(str);
	return (res);
}

int	add_print_char(int c)
{
	int	res ;

	res = 1;
	ft_putchar_fd((char)c, STDOUT);
	return (res);
}
