/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:32:02 by jvets             #+#    #+#             */
/*   Updated: 2023/09/14 18:38:31 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("%1c\n", 'a');
	ft_printf("%1c\n", 'a');
	printf("%.11d\n", (int)-2147483648);
	ft_printf("%.11d\n", (int)-2147483648);
	printf("%.5d\n", -1214);
	ft_printf("%.5d\n", -1234);
	printf("|%.1s|\n", "");
	ft_printf("|%.1s|\n", "");
	printf("% 13d\n", 1234);
	ft_printf("% 13d\n", 1234);
	printf("%10.13d\n", 1234);
	ft_printf("%10.13d\n", 1234);
	printf("% 5i\n", 5);
	ft_printf("% 5i\n", 5);
	printf("%+d\n", 0);
	ft_printf("%+d\n", 0);
	printf("%+5i\n", 25);
	ft_printf("%+5i\n", 25);
	printf("%+05i\n", 25);
	ft_printf("%+05i\n", 25);
	printf("%+05i\n", -25);
	ft_printf("%+05i\n", -25);
	printf("printf: %#x\n", 0);
	ft_printf("printf: %.#x\n", 0);
	printf("printf: %#x\n", -1);
	ft_printf("printf: %.#x\n", -1);
	printf("printf: %#x\n", 1);
	ft_printf("printf: %.#x\n", 1);
	printf("printf: %.2x\n", 1);
	ft_printf("printf: %.2x\n", 1);
	printf("printf: %.2x\n", 10);
	ft_printf("printf: %.2x\n", 10);
	printf("printf: %.3x\n", 11);
	ft_printf("printf: %.3x\n", 11);
	printf("printf: %.2u\n", 1);
	ft_printf("printf: %.2u\n", 1);
	printf("printf: %.3u\n", 11);
	ft_printf("printf: %.3u\n", 11);
	printf("printf: %.2i\n", -1);
	ft_printf("printf: %.2i\n", -1);
	printf("printf: %.4i\n", 15);
	ft_printf("printf: %.4i\n", 15);
	printf("printf: %.s\n", "");
	ft_printf("ft_printf: %.s\n", "");
        printf("printf:  %.1s\n", "");
        ft_printf("ft_printf:  %.1s\n", "");
        printf("printf: %.1s \n", "");
        ft_printf("ft_printf: %.1s \n", "");
        printf(" %.s \n", "");
        ft_printf(" %.s \n", "");
        printf(" %.s \n", "-");
        ft_printf(" %.s \n", "-");
        printf(" %.2s %.1s \n", "", "-");
        ft_printf(" %.2s %.1s \n", "", "-");
        printf(" %.3s %.2s \n", " - ", "");
        ft_printf(" %.3s %.2s \n", " - ", "");
        printf("pf: %.1s %.2s %.3s %.4s \n", " - ", "", "4", "");
        ft_printf("ft: %.1s %.2s %.3s %.4s \n", " - ", "", "4", "");
        printf("pf: %.2s %.3s %.4s %.5s %.1s \n", "abc", "", "d", "", "ef");
        ft_printf("ft: %.2s %.3s %.4s %.5s %.1s \n", "abc", "", "d", "", "ef");
	printf("%04d\n", -14);
	ft_printf("%04d\n\n", -14);
	printf("%04d\n", 9);
	ft_printf("%04d\n\n", 9);

	printf("%-4u\n", 9);
	ft_printf("%-4u\n", 9);

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
	printf("%-5i|\n", 50);
	ft_printf("%-5i|\n", 50);
	printf("%5i\n", 50);
	ft_printf("%5i\n", 50);


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
