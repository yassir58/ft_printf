/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:17:18 by yelatman          #+#    #+#             */
/*   Updated: 2021/11/17 18:28:06 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	count_unsigned(unsigned int nbr)
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

static void	ft_putunsigned_fd(int n, int fd)
{
	unsigned int	uns;

	uns = n;
	if (uns >= 10)
	{
		ft_putnbr_fd(uns / 10, fd);
		ft_putnbr_fd(uns % 10, fd);
	}
	else
	{
		ft_putchar_fd(uns + '0', fd);
	}
}

int	print_unsigned(int nbr)
{
	int				res;
	unsigned int	nb;

	res = 0;
	nb = nbr;
	res = count_unsigned(nb);
	ft_putunsigned_fd(nbr, STDOUT);
	return (res);
}
