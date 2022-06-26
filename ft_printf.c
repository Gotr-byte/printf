/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:01:37 by pbiederm          #+#    #+#             */
/*   Updated: 2022/06/26 10:55:50 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void	ft_putchar(char c);
int	ft_printf(const char *, ...);

int	ft_printf(const char *, ...)
{
char cType = *ptrInputStringCopy;
ptrInputStringCopy++;
while( *ptrInputStringCopy )
{
	if( *ptrInputStringCopy != '%' )
		{
			putchar( *ptrInputStringCopy ); 
			ptrInputStringCopy++; 
			continue;
		}
	if (cType == 'd')
		{
			int intValue  =   va_arg( argumentList, int );
			printf( " %d ", intValue );
			++number_of_arguments;
			break;
		}
}
	

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main ()
{
	int	main(void)
{
	int i;
	char * aline = "NULL";
	char * bline = "bline";
	int t;

	i = 0;
	t = -2147483648;

	ft_printf ("Hi \"party\nhungover\\shoes  \n\0flipflops %d %s %d %s ", i, aline, t, bline);
	printf ("Hi \"party\nhungover\\shoes  \n\0flipflops %d %s %d %s", i, aline, t, bline);

}
}
