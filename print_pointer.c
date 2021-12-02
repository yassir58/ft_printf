/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:22:37 by yelatman          #+#    #+#             */
/*   Updated: 2021/11/30 14:17:01 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_pointer(unsigned long addr)
{
	int	length;

	if (addr != 0)
	{
		length = convert_long(addr);
	}
	else
	{
		ft_putstr_fd("0x", STDOUT);
		ft_putchar_fd('0', STDOUT);
		length = 3;
	}
	return (length);
}
