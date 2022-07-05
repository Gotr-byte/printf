/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:01:37 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/05 08:33:24 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include "ft_itoa_lu.c"
#include "hext.c"
#include "hexxt.c"

void	ft_putchar(char c);
int		ft_printf(const char *prt, ...);
void	ft_putstr(char *str);
char	*ft_itoa(int n);
char	*append(char *ret_str, long long int long_n, int index);
static int	pow_ten(int n);
static int	count_digit(long long n);

static int	count_digit(long long n)
{
	if (n / 10 == 0)
		return (1);
	return (1 + count_digit(n / 10));
}

static int	pow_ten(int n)
{
	int	pow_ten;

	if (n == 0)
	{
		pow_ten = 1;
		return (pow_ten);
	}
	pow_ten = 1;
	while (n--)
		pow_ten = pow_ten * 10;
	return (pow_ten);
}

char	*append(char *ret_str, long long int long_n, int index)
{
	int				ten_count;

	ten_count = count_digit(long_n);
	while (ten_count--)
	{
		ret_str[index] = long_n / pow_ten(ten_count) + '0';
		long_n = long_n % pow_ten(ten_count);
		index++;
	}
	ret_str[index] = '\0';
	return (ret_str);
}

char	*ft_itoa(int n)
{
	char			*ret_str;
	int				index;
	long long int	long_n;

	long_n = (long long int)n;
	index = 0;
	if (long_n > 2147483647)
		return (NULL);
	if (long_n < -2147483648)
		return (NULL);
	if (long_n < 0)
	{
		ret_str = (char *)malloc((count_digit(long_n) + 2) * sizeof(char));
		if (!ret_str)
			return (NULL);
		ret_str[index] = '-';
		long_n = long_n * -1;
		index++;
	}
	else
		ret_str = (char *)malloc((count_digit(long_n) + 1) * sizeof(char));
	if (!ret_str)
		return (NULL);
	ret_str = append(ret_str, long_n, index);
	return (ret_str);
}

char hex_digit (int v) 
{
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10; // <-- Here
}

void print_address_hex (void* p0)
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
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write (1, str, sizeof(str));
		str = str + 1;
	}
}
				
void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_printf(const char *prt, ...)
{
char 			*parse;
unsigned int	j;
char			*str;
va_list			arg;
int				n;
void			*melkor;
size_t			k;
// size_t			u;
	
melkor = malloc (sizeof(melkor));	

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
	else if (*parse == 'p' && *parse != '\0')
		{
			melkor = va_arg(arg, void*);
			print_address_hex(melkor);
			free(melkor);
			parse++;
		}
	else if ((*parse == 'd' || *parse == 'i' )&& *parse != '\0')
		{
			k = va_arg(arg, int);
			str = ft_itoa(k);
			ft_putstr(str);
			free(str);
			parse++;
		}
	else if (*parse == 'u' && *parse != '\0')
		{
			k = va_arg(arg, unsigned int);
			str = ft_itoa_lu(k);
			ft_putstr(str);
			free(str);
			parse++;
		}
	else if (*parse == 'x' && *parse != '\0')
		{
			k = va_arg(arg, unsigned int);
			str = ft_itoa_x(k);
			ft_putstr(str);
			free(str);
			parse++;
		}
	else if (*parse == 'x' && *parse != '\0')
		{
			k = va_arg(arg, unsigned int);
			str = ft_itoa_x(k);
			ft_putstr(str);
			free(str);
			parse++;
		}
	else if (*parse == 'X' && *parse != '\0')
		{
			k = va_arg(arg, unsigned int);
			str = ft_itoa_xx(k);
			ft_putstr(str);
			free(str);
			parse++;
		}
	else if (*parse == '%' && *parse != '\0')
		{
			ft_putchar('%');
			parse++;
		}
}	
va_end(arg);
}

int	main ()
{
	// int i;
	// char * aline = "NULL";
	char * bline;
	void	*melkor;
	
	melkor = malloc (sizeof(melkor));	
	bline = "blineeeeer";
	int t;
	unsigned int u;

	// i = 0;
	t = -2147483648;
	u = 255;

	// ft_printf ("Hi \"party\nhungover\\shoes  \n\0flipflops %d %s %d %s ", i, aline, t, bline);
	// printf ("Hi \"party\nhungover\\shoes  \n\0flipflops %d %s %d %s", i, aline, t, bline);
	ft_printf ("All my Heroes!%c %s %p %d %i	%u %x %X %%!!!!\n", 'c', bline, melkor, t, t, u, u, u);
	printf ("All my Heroes!%c %s %p %d %i	%u %x %X %%!!!!\n", 'c', bline, melkor, t, t, u, u, u);
}

// Everyone who doesn't have a mac: printf has different implementations on mac and other systems.
//  I think the only difference is the NULL void pointer. 
//  So your printf should print "0x0" in case of ft_printf("%p", NULL);
//   to pass moulinette

