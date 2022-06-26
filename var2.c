/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:32:50 by pbiederm          #+#    #+#             */
/*   Updated: 2022/06/25 18:37:49 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int	addingNumbers (int nHowMany, ...)
{
	int	nSum = 0;
	
	va_list	intArgumentPointer;
	va_start	(intArgumentPointer, nHowMany);
	for (int i = 0; i < nHowMany; i++)
		nSum += va_arg(intArgumentPointer, int);
	va_end (intArgumentPointer);

	return (nSum);	
}

// int main (int argc, char **argv)
int main (void)
{
	// addingNumbers( number, atoi( argv[1] ) );
	// if (argc < 2){};
	// if (argc > 6){};
	// int ourPrint(char *string, ...);
	// while (char *prtInputStringCopy);
	// {
	// 	if(*ptrInputStringCopy != '%')
	// 	{
	// 		putchar(*ptrInputStringCopy); ptrInputStringCopy++; continue;
	// 	}
	// }
	// char cType = * ptrInputStringCopy; ptrInputStringCopy++;
	// switch ( cType)
	// {
	// 	case 'd' : int intValue = va_arg(	argumentList, int)
	// 	printf( "%d, intValue");
	// 	++number_of_arguments;
	// 	break;
	// }
	// {
	// case /* constant-expression */:
	// 	/* code */
	// 	break;
	// default:
	// 	break;
	// }
	system("clear");
	printf( "\n\n Variadic Functions \n\n");
	printf( "\n 10 + 20 = %d ",	addingNumbers (2, 10, 20));
	printf( "\n 10 + 20 + 30 = %d", addingNumbers (3, 10, 20, 30));
	printf( "\n 10 + 20 + 30 + 40 = %d", addingNumbers (4, 10, 20, 30, 40));
	printf( "\n \n");

	return EXIT_SUCCESS;
}