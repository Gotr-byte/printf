/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hext.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:52:16 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/04 15:52:16 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <unistd.h>
// #include <limits.h>
// #include <stdlib.h>
// #include <stdio.h>
#include "printf.h"

static char hex_digit_x (size_t v);

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
		ret_str[index] =hex_digit_x(long_n / pow_hexdec(hexdec_count)); 
		long_n = long_n % pow_hexdec(hexdec_count);
		index++;
	}
	ret_str[index] = '\0';
	return (ret_str);
}

char	*ft_itoa_x(unsigned long n)
{
	char			*ret_str;
	size_t	index;
	size_t			long_n;

	long_n = (size_t)n;
	index = 0;
	if (long_n > 4294967295)
		return (NULL);
	// if (long_n < 0)
	// 	return (NULL);
	else
		ret_str = (char *)malloc((count_hexdec(long_n) + 1) * sizeof(char));
	if (!ret_str)
		return (NULL);
	ret_str = append_x(ret_str, long_n, index);
	return (ret_str);
}

static char hex_digit_x (size_t v) 
{
    // if (v >= 0 && v < 10)
	if (v < 10)
        return '0' + v;
    else
        return 'a' + v - 10;
}

// int main(void)
// {
// 	int t;

// 	t = 512;

// 	// printf	("%%d: %d\n%%x: %x\n", t, t);
// 	printf("ft_itoa_x(%d): %s\n",t, ft_itoa_x(t));
// 	printf("printf (%d): %x\n", t, t);
// }