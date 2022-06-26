/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:49:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/06/25 09:49:46 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void print_inits(int num, ...)
{
	va_list args;

	va_start(args, num);

	for (int i=0; i<num; i++)
	{
		int value = va_arg(args, int);
		printf("%d %d\n", i, value);
	}
	va_end(args);
}

int main ()
{
	print_inits(5 , 14, 15, 2345, -33, 90);
}
