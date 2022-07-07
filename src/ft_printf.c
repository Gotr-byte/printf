/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:01:37 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/07 21:54:26 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// char	*prt_par_flag(unsigned int prt, char *parse, char flag)
// {
// 	if (flag == 'u')
// 		return (prt_par_lu(prt, parse));
// 	else if (flag == 'x')
// 		return (prt_par_x(prt, parse));
// 	else if (flag == 'X')
// 		return (prt_par_xx(prt, parse));
// 	return (NULL);
// }

// char	*prt_par_per(char *parse)
// {
// 	ft_putchar('%');
// 	return (parse + 1);
// }

// char	*prt_par_xx(unsigned int prt, char *parse)
// {
// 	char	*str;

// 	str = ft_itoa_xx(prt);
// 	ft_putstr(str);
// 	free(str);
// 	return (parse + 1);
// }

// char	*prt_par_x(unsigned int prt, char *parse)
// {
// 	char	*str;

// 	str = ft_itoa_x(prt);
// 	ft_putstr(str);
// 	free(str);
// 	return (parse + 1);
// }

// char	*prt_par_lu(unsigned int prt, char *parse)
// {
// 	char	*str;

// 	str = ft_itoa_lu(prt);
// 	ft_putstr(str);
// 	free(str);
// 	return (parse + 1);
// }

char	*prt_par_di(int prt, char *parse)
{
	char	*str;

	str = ft_itoa(prt);
	ft_putstr(str);
	free(str);
	return (parse + 1);
}

char	*ft_putstr_par(char *str, char *parse)
{
	while (*str != '\0')
	{
		write (1, str, sizeof(char));
		str = str + 1;
	}
	return (parse + 1);
}

char	*ft_putchar_par(char c, char *parse)
{
	write (1, &c, sizeof(char));
	return (parse + 1);
}

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
	char			*p;
	va_list			arg;

	va_start(arg, prt);
	p = (char *)prt;
	while (*p != '\0')
	{
		while (*p != '%' && *p != '\0')
			p = ft_putchar_par(*p, p);
		p++;
		if (*p == 'c' && *p != '\0')
			p = ft_putchar_par(va_arg(arg, int), p);
		else if (*p == 's' && *p != '\0')
			p = ft_putstr_par(va_arg(arg, char *), p);
		else if (*p == 'p' && *p != '\0')
			p = print_address_hex(va_arg(arg, void *), p);
		else if ((*p == 'd' || *p == 'i' ) && *p != '\0')
			p = prt_par_di(va_arg(arg, int), p);
		else if (*p == '%' && *p != '\0')
			p = prt_par_per(p);
		else if ((*p == 'u' || *p == 'x' || *p == 'X') && *p != '\0')
			p = prt_par_flag(va_arg(arg, unsigned int), p, *p);
	}
	va_end(arg);
	return (0);
}

// int	main ()
// {
// 	// int i;
// 	// char * aline = "NULL";
// 	char * bline;
// 	void	*melkor;
// 	melkor = malloc (sizeof(melkor));	
// 	bline = "blineeeeer";
// 	int t;
// 	unsigned int u;

// 	// i = 0;
// 	t = -2147483648;
// 	u = 255;

	// ft_printf ("Hi \"party\nhungover\\shoes
	// \n\0flipflops %d %s %d %s ", i, aline, t, bline);
	// printf ("Hi \"party\nhungover\\shoes
	//   \n\0flipflops %d %s %d %s", i, aline, t, bline);
// 	ft_printf ("All my Heroes!%c %s %p %d %i 
//%u %x %X %%!!!!\n", 'e', bline, melkor, t, t, u, u, u);
// 	printf ("All my Heroes!%c %s %p %d %i
// 		%u %x %X %%!!!!\n", 'e', bline, melkor, t, t, u, u, u);
// }
