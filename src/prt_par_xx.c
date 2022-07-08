/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_par_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:07:00 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/08 19:11:20 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write (1, str, 1);
		str = str + 1;
	}
}

char	*prt_par_xx(unsigned int prt, char *parse)
{
	char	*str;

	str = ft_itoa_xx(prt);
	ft_putstr(str);
	free(str);
	return (parse + 1);
}
