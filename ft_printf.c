/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:01:37 by pbiederm          #+#    #+#             */
/*   Updated: 2022/06/30 10:42:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void	ft_putchar(char c);
int	ft_printf(const char *prt, ...);
void	ft_putstr(char *str);

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write (1, str, 1);
		str = str + 1;
	}
}

int	ft_printf(const char *prt, ...)
{
char 			*parse;
unsigned int	j;
char			*str;
va_list			arg;
int				n;

va_start(arg, prt);
n = 0;
parse = (char*)prt;

while (*parse != '\0')
{
	while (*parse != '%' && *parse != '\0')
	{
	ft_putchar(*parse);
	parse++;
	}
	if(*parse != '\0')
		parse++;
	
	if (*parse == 'c' && *parse != '\0')
		{
		j = va_arg(arg, int);
		ft_putchar(j);
		parse++;	
		}
	else if (*parse == 's' && *parse != '\0')
		{
			str = va_arg(arg, char*);
			ft_putstr(str);
			parse++;
		}
}
va_end(arg);
}
				
void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main ()
{
	// int i;
	// char * aline = "NULL";
	char * bline;
	
	bline = "blineeeeer";
	// int t;

	// i = 0;
	// t = -2147483648;

	// ft_printf ("Hi \"party\nhungover\\shoes  \n\0flipflops %d %s %d %s ", i, aline, t, bline);
	// printf ("Hi \"party\nhungover\\shoes  \n\0flipflops %d %s %d %s", i, aline, t, bline);
	ft_printf ("All my Heroes!%c %s 1111!!!!\n", 'c', bline);
}


