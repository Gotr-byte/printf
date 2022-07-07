/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:46:21 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/07 22:00:02 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*prt_par_flag(unsigned int prt, char *parse, char flag)
{
	if (flag == 'u')
		return (prt_par_lu(prt, parse));
	else if (flag == 'x')
		return (prt_par_x(prt, parse));
	else if (flag == 'X')
		return (prt_par_xx(prt, parse));
	return (NULL);
}

char	*prt_par_per(char *parse)
{
	ft_putchar('%');
	return (parse + 1);
}

char	*prt_par_xx(unsigned int prt, char *parse)
{
	char	*str;

	str = ft_itoa_xx(prt);
	ft_putstr(str);
	free(str);
	return (parse + 1);
}

char	*prt_par_x(unsigned int prt, char *parse)
{
	char	*str;

	str = ft_itoa_x(prt);
	ft_putstr(str);
	free(str);
	return (parse + 1);
}

char	*prt_par_lu(unsigned int prt, char *parse)
{
	char	*str;

	str = ft_itoa_lu(prt);
	ft_putstr(str);
	free(str);
	return (parse + 1);
}
