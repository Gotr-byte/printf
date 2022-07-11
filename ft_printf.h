/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:09:12 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/09 11:09:12 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
// # include "ft_itoa_lu.c"
// # include "ft_itoa_x.c"
// # include "ft_itoa_xx.c"
// # include "../libft/libft.h"
// # include "../libft/ft_itoa.c"
// # include "print_hex_address.c"
// // # include "printf.h"
// // # include "flags.c"
// // # include "ft_printf.c"
// // # include "ft_putchar.c"
// #include "prt_par_per.c"
// #include "prt_par_xx.c"
// #include "prt_par_x.c"
// #include "prt_par_lu.c"

void		ft_putchar(char c);
int			ft_printf(const char *prt, ...);
void		ft_putstr(char *str);
// char		*ft_itoa(int n);
char		*ft_itoa_x(unsigned long n);
char		*ft_itoa_xx(unsigned long n);
char		*append(char *ret_str, long long int long_n, int index);
char		*prt_par_per(char *parse);
char		*prt_par_xx(unsigned int prt, char *parse);
char		*prt_par_x(unsigned int prt, char *parse);
char		*prt_par_lu(unsigned int prt, char *parse);
char		*prt_par_di(int prt, char *parse);
char		*print_address_hex(void *p0, char *parse);
char		*ft_putstr_par(char *str, char *parse);
char		*ft_putchar_par(char c, char *parse);
char		*prt_par_flag(unsigned int prt, char *parse, char flag);
char		*ft_itoa_lu(unsigned long n);
#endif