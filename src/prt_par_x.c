/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_par_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:12:17 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/08 19:14:58 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*prt_par_x(unsigned int prt, char *parse)
{
	char	*str;

	str = ft_itoa_x(prt);
	ft_putstr(str);
	free(str);
	return (parse + 1);
}
