/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 08:23:08 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/04 08:23:08 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_itoa
// Prototype char *ft_itoa(int n);
// Turn in files -
// Parameters n: the integer to convert.
// Return value The string representing the integer.
// NULL if the allocation fails.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a string
// representing the integer received as
// 2,147,483,647 - max intiger value

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

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
	size_t	index;
	size_t			long_n;

	long_n = (size_t)n;
	index = 0;
	if (long_n > 4294967295)
		return (NULL);
	if (long_n < 0)
		return (NULL);
	else
		ret_str = (char *)malloc((count_digit_lu(long_n) + 1) * sizeof(char));
	if (!ret_str)
		return (NULL);
	ret_str = append_lu(ret_str, long_n, index);
	return (ret_str);
}
// int    main(void)
// {
//     printf("itoa: %s", ft_itoa_lu(-9));
//     printf("itoa: %s", ft_itoa_lu(0));
//     printf("itoa: %s", ft_itoa_lu(1231234));
//     printf("itoa: %s", ft_itoa_lu(4294967295));
// 	printf("itoa: %s", ft_itoa_lu(4294967296));
// 	printf("itoa: %s", ft_itoa_lu(42949672960009));
//     return (0);
// }
