/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:10:12 by yelatman          #+#    #+#             */
/*   Updated: 2021/11/30 14:15:48 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	convert_long(unsigned long nbr)
{
	int		i;
	int		rem;
	char	hex[100];

	ft_putstr_fd("0x", STDOUT);
	i = 0;
	rem = 0;
	while (nbr != 0)
	{
		rem = nbr % 16;
		if (rem < 10)
			rem = rem + 48;
		else
			rem = rem + 87;
		hex[i] = rem;
		i++;
		nbr = nbr / 16;
	}
	hex[i] = '\0';
	while (i--)
		write(STDOUT, &hex[i], 1);
	return (ft_strlen(hex) + 2);
}

int	convert_base(unsigned int nbr, int indx)
{
	int		i;
	int		rem;
	char	hex[50];

	i = 0;
	rem = 0;
	while (nbr != 0)
	{
		rem = nbr % 16;
		if (rem < 10)
			rem = rem + 48;
		else
			rem = rem + indx;
		hex[i] = rem;
		i++;
		nbr = nbr / 16;
	}
	hex[i] = '\0';
	while (i--)
		ft_putchar_fd(hex[i], STDOUT);
	return (ft_strlen(hex));
}

int	print_hex(unsigned int nbr, char c)
{
	int	length;

	length = 0;
	if (nbr != 0)
	{
		if (c == 'x')
			length = convert_base(nbr, 87);
		else if (c == 'X')
			length = convert_base(nbr, 55);
	}
	else
	{
		length = 1;
		ft_putchar_fd('0', STDOUT);
	}	
	return (length);
}
