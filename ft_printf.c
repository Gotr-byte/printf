/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:29:07 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/11 15:39:32 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include "./libft/libft.h"
#include "ft_printf.h"

int				ft_putstr_i(char *str);
static	char	hex_digit_x(size_t v);
int				adr_hex(void *p0);
int				di(int prt);
int				ft_putchar_i(char c);

// static int	count_hexdec_xx(size_t n)
// {
// 	if (n / 16 == 0)
// 		return (1);
// 	return (1 + count_hexdec_xx(n / 16));
// }

// static size_t	pow_hexdec_xx(size_t n)
// {
// 	size_t	pow_ten;

// 	if (n == 0)
// 	{
// 		pow_ten = 1;
// 		return (pow_ten);
// 	}
// 	pow_ten = 1;
// 	while (n--)
// 		pow_ten = pow_ten * 16;
// 	return (pow_ten);
// }

// static char	*append_xx(char *ret_str, size_t long_n, size_t index)
// {
// 	size_t				hexdec_count;

// 	hexdec_count = count_hexdec_xx(long_n);
// 	while (hexdec_count--)
// 	{
// 		ret_str[index] = hex_digit_xx(long_n / pow_hexdec_xx(hexdec_count));
// 		long_n = long_n % pow_hexdec_xx(hexdec_count);
// 		index++;
// 	}
// 	ret_str[index] = '\0';
// 	return (ret_str);
// }

// char	*ft_itoa_xx(unsigned long n)
// {
// 	char			*ret_str;
// 	size_t			index;
// 	size_t			long_n;

// 	long_n = (size_t)n;
// 	index = 0;
// 	if (long_n > 4294967295)
// 		return (NULL);
// 	else
// 		ret_str = (char *)malloc((count_hexdec_xx(long_n) + 1) * sizeof(char));
// 	if (!ret_str)
// 		return (NULL);
// 	ret_str = append_xx(ret_str, long_n, index);
// 	return (ret_str);
// }

// static char	hex_digit_xx(size_t v)
// {
// 	if (v < 10)
// 		return ('0' + v);
// 	else
// 		return ('A' + v - 10);
// }

static int	count_hexdec(size_t n)
{
	if (n / 16 == 0)
		return (1);
	return (1 + count_hexdec(n / 16));
}

static size_t	pow_hexdec(size_t n)
{
	size_t	pow_ten;

	if (n == 0)
	{
		pow_ten = 1;
		return (pow_ten);
	}
	pow_ten = 1;
	while (n--)
		pow_ten = pow_ten * 16;
	return (pow_ten);
}

static char	*append_x(char *ret_str, size_t long_n, size_t index)
{
	size_t				hexdec_count;

	hexdec_count = count_hexdec(long_n);
	while (hexdec_count--)
	{
		ret_str[index] = hex_digit_x(long_n / pow_hexdec(hexdec_count));
		long_n = long_n % pow_hexdec(hexdec_count);
		index++;
	}
	ret_str[index] = '\0';
	return (ret_str);
}

char	*ft_itoa_x(unsigned long n)
{
	char			*ret_str;
	size_t			index;
	size_t			long_n;

	long_n = (size_t)n;
	index = 0;
	if (long_n > 4294967295)
		return (NULL);
	else
		ret_str = (char *)malloc((count_hexdec(long_n) + 1) * sizeof(char));
	if (!ret_str)
		return (NULL);
	ret_str = append_x(ret_str, long_n, index);
	return (ret_str);
}

static char	hex_digit_x(size_t v)
{
	if (v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

static int	count_digit_lu(size_t n)
{
	if (n / 10 == 0)
		return (1);
	return (1 + count_digit_lu(n / 10));
}

static int	pow_ten_lu(size_t n)
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

static char	*append_lu(char *ret_str, size_t long_n, size_t index)
{
	size_t				ten_count;

	ten_count = count_digit_lu(long_n);
	while (ten_count--)
	{
		ret_str[index] = long_n / pow_ten_lu(ten_count) + '0';
		long_n = long_n % pow_ten_lu(ten_count);
		index++;
	}
	ret_str[index] = '\0';
	return (ret_str);
}

char	*ft_itoa_lu(unsigned long n)
{
	char			*ret_str;
	size_t			index;
	size_t			long_n;

	long_n = (size_t)n;
	index = 0;
	if (long_n > 4294967295)
		return (NULL);
	else
		ret_str = (char *)malloc((count_digit_lu(long_n) + 1) * sizeof(char));
	if (!ret_str)
		return (NULL);
	ret_str = append_lu(ret_str, long_n, index);
	return (ret_str);
}

int		prt_par_xx(unsigned int prt)
{
	char	*str;
	int		i;

	str = ft_itoa_xx(prt);
	i = ft_putstr_i(str);
	free(str);
	return (i);
}

int		prt_par_x(unsigned int prt)
{
	char	*str;
	int		i;

	str = ft_itoa_x(prt);
	i = ft_putstr_i(str);
	free(str);
	return (i);
}


int	prt_par_lu(unsigned int prt)
{
	char	*str;
	int		i;

	str = ft_itoa_lu(prt);
	i = ft_putstr_i(str);
	free(str);
	return (i);
}

int	flag(va_list arg, char flag)
{
	if (flag == 'u')
		return (prt_par_lu(va_arg(arg, unsigned int)));
	else if (flag == 'x')
		return (prt_par_x(va_arg(arg, unsigned int)));
	else if (flag == 'X')
		return (prt_par_xx(va_arg(arg, unsigned int)));
	else if (flag == 'p')
		// return (prt_par_x(va_arg(arg, unsigned int)));
		return (adr_hex(va_arg(arg, void*)));
	else if ((flag == 'd' || flag == 'i' ))
		return (di(va_arg(arg, int)));
	else if (flag == 'c')
		return (ft_putchar_i(va_arg(arg, int)));
	else if (flag == 's')
		return (ft_putstr_i(va_arg(arg, char*)));
	else if (flag == '%')
		return (write(1, "%", sizeof(char)));
	return (0);
}

// static int	count_digit(long long n)
// {
// 	if (n / 10 == 0)
// 		return (1);
// 	return (1 + count_digit(n / 10));
// }

// static int	pow_ten(int n)
// {
// 	int	pow_ten;

// 	if (n == 0)
// 	{
// 		pow_ten = 1;
// 		return (pow_ten);
// 	}
// 	pow_ten = 1;
// 	while (n--)
// 		pow_ten = pow_ten * 10;
// 	return (pow_ten);
// }

// static char	*append(char *ret_str, long long int long_n, int index)
// {
// 	int				ten_count;

// 	ten_count = count_digit(long_n);
// 	while (ten_count--)
// 	{
// 		ret_str[index] = long_n / pow_ten(ten_count) + '0';
// 		long_n = long_n % pow_ten(ten_count);
// 		index++;
// 	}
// 	ret_str[index] = '\0';
// 	return (ret_str);
// }

// char	*ft_itoa(int n)
// {
// 	char			*ret_str;
// 	int				index;
// 	long long int	long_n;

// 	long_n = (long long int)n;
// 	index = 0;
// 	if (long_n > 2147483647)
// 		return (NULL);
// 	if (long_n < -2147483648)
// 		return (NULL);
// 	if (long_n < 0)
// 	{
// 		ret_str = (char *)malloc((count_digit(long_n) + 2) * sizeof(char));
// 		if (!ret_str)
// 			return (NULL);
// 		ret_str[index] = '-';
// 		long_n = long_n * -1;
// 		index++;
// 	}
// 	else
// 		ret_str = (char *)malloc((count_digit(long_n) + 1) * sizeof(char));
// 	if (!ret_str)
// 		return (NULL);
// 	ret_str = append(ret_str, long_n, index);
// 	return (ret_str);
// }

int	ft_putstr_i(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
			return(write(1, "(null)", 6 * sizeof(char)));
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	di(int prt)
{
	char	*str;
	int		i;

	str = ft_itoa(prt);
	i = ft_putstr_i(str);
	free(str);
	return (i);
}

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

static char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

int	adr_hex(void *p0)
{
	int			i;
	int			ret;
	uintptr_t	p;
	static int	print_flag;
	char		adr_store;

	if (p0 == NULL)
	{
		ret = ft_putchar('0');
		ret = ret + ft_putchar('x');
		ret = ret + ft_putchar('0');
		return (ret);
	}
	p = (uintptr_t)p0;
	print_flag = 0;
	ret = ft_putchar_i('0');
	ret = ret + ft_putchar_i('x');
	i = (sizeof(p) << 3) - 4;
	while (i >= 0)
	{
		adr_store = hex_digit((p >> i) & 0xf);
		if (adr_store > '0' || print_flag > 0)
		{
				ret = ret + ft_putchar_i(adr_store);
				print_flag = 1;
		}
		i -= 4;
	}
	return (ret);
}

int	ft_putchar_i(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printf(const char *prt, ...)
{
	va_list			arg;
	int				n;
	int				ret;

	n = 0;
	ret = 0;
	va_start(arg, prt);
	while (prt[n] != '\0')
	{
		if (prt[n] != '%')
			ret = ret + ft_putchar_i(prt[n]);
		else if (prt[n++] == '%')
			ret = ret + flag(arg, prt[n]);
		n++;
	}
	va_end(arg);
	return (ret);
}

// int	main(void)
// {
// 	char	*bline;
// 	void	*melkor;
	// int		tez;
	// int		minne;

// 	bline = "blineeeeer";
// 	melkor = malloc(sizeof(melkor));
// 	melkor = &tez;
// 	tez = ft_printf ("%%Eldrich blast %s %d %i %u %c %p %x %X%%\n", "is cast and deals", 24, -21, 111, 'c', melkor, 111, 111);
// 	minne = printf ("%%Eldrich blast %s %d %i %u %c %p %x %X%%\n", "is cast and deals", 24, -21, 111, 'c', melkor, 111, 111);
// 	tez = ft_printf ("NULL %s NULL\n", NULL);
// 	minne = printf ("NULL %s NULL\n", NULL);

// 	printf ("ft_printf: %d\n", tez);
// 	printf ("printf: %d\n", minne);
// }
