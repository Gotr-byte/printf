/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voidp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:12:59 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/06 16:12:59 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

char hex_digit (int v) 
{
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10; // <-- Here
}

char *print_address_hex (void* p0, char *parse)
{
    int i;
    uintptr_t p;
	
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