/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:03:13 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/09 11:03:33 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

char	*print_address_hex(void *p0, char *parse)
{
	int			i;
	uintptr_t	p;

	p = (uintptr_t)p0;
	ft_putchar('0');
	ft_putchar('x');
	i = (sizeof(p) << 3) - 20;
	while (i >= 0)
	{
		ft_putchar(hex_digit((p >> i) & 0xf));
		i -= 4;
	}
	return (parse + 1);
}
