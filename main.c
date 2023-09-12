/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:32:02 by jvets             #+#    #+#             */
/*   Updated: 2023/09/11 22:56:14 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("MANDATÓRIO\n\n");
	printf("Char\n");
	printf("%c\n", 'a');
	ft_printf("%c\n\n", 'a');
	printf("%c%c%c\n", 'a', 'b', 'c');
	ft_printf("%c%c%c\n\n", 'a', 'b', 'c');
	printf("%cb%c\n", 'a', 'c');
	ft_printf("%cb%c\n\n", 'a', 'c');

	printf("String\n");
	printf("%s\n", "abc");
	ft_printf("%s\n\n", "abc");
	printf("%s %s\n", "abc", "def");
	ft_printf("%s %s\n\n", "abc", "def");
	//printf(" NULL %s NULL ", NULL);

	printf("Int\n");
	printf("%i\n", 5);
	ft_printf("%i\n\n", 5);

	printf("Pointer\n");
	int i = 1;
	int c = 0;
	printf("%p\n", &i);
	ft_printf("%p\n", &i);
	printf(" %p %p \n", &c, &c);
	ft_printf(" %p %p \n", &c, &c);

	printf("Unsinged\n");
	printf("printf: %u\n", -1);
	ft_printf("%u\n\n", -1);

	printf("flag specifier x\n");
	printf("%x\n", 0);
	ft_printf("%x\n\n", 0);
	

	printf("BONUS\n\n");
	printf("flag specifier 0\n");
	printf("%5c\n", 'j');
	ft_printf("%5c\n", 'j');
	printf("%-5c%c\n", 'j', '|');
	ft_printf("%-5c%c\n", 'j', '|');
	printf("%10c\n", 'a');
	ft_printf("%10c\n\n", 'a');
	printf("%5c\n", 'a');
	ft_printf("%5c\n\n", 'a');


	printf("%+i\n", 10);
	printf("%8i\n", 10);
	printf("%-8i\n", 10);
	printf("%08i\n", 10);
	printf("%+08i\n", 10);
	printf("%+-8i\n", 10);
	printf("%-+8i\n", 10);
	//ft_printf("%%dkd");
	return (0);
}
