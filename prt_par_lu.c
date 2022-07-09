/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_par_lu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:17:52 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/09 11:03:37 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prt_par_lu(unsigned int prt, char *parse)
{
	char	*str;

	str = ft_itoa_lu(prt);
	ft_putstr(str);
	free(str);
	return (parse + 1);
}
