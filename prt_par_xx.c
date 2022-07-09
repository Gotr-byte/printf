/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_par_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:07:00 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/09 11:03:51 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prt_par_xx(unsigned int prt, char *parse)
{
	char	*str;

	str = ft_itoa_xx(prt);
	ft_putstr(str);
	free(str);
	return (parse + 1);
}
