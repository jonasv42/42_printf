/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:32:02 by jvets             #+#    #+#             */
/*   Updated: 2023/09/20 22:40:39 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int	main(void)

{
	printf("MANDATORY\n\n");

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

	printf("Int\n");
	printf("%i\n", 54);
	ft_printf("%i\n\n", 54);

	printf("Pointer\n");
	int i = 1;
	int c = 0;
	printf("%p\n", &i);
	ft_printf("%p\n\n", &i);
	printf(" %p %p \n", &c, &c);
	ft_printf(" %p %p \n\n", &c, &c);

	printf("Unsinged\n");
	printf("%u\n", -1);
	ft_printf("%u\n\n", -1);

	printf("flag specifier x\n");
	printf("%x\n", 0);
	ft_printf("%x\n\n", 0);
	

	printf("BONUS\n\n");
	printf("flag 0\n");
	printf("%01d\n", 0);
	ft_printf("%01d\n\n", 0);
	printf("%04d\n", 9);
	ft_printf("%04d\n\n", 9);
	printf("%010d\n", -42);
	ft_printf("%010d\n\n\n", -42);
	printf("%01i\n", -1);
	ft_printf("%01i\n\n", -1);
	printf("%010i\n", 15);
	ft_printf("%010i\n\n", 15);
	printf("%03i\n", -101);
	ft_printf("%03i\n\n\n", -101);

	printf("flag .\n");
	printf("%.10d\n", 42);
	ft_printf("%.10d\n\n", 42);
	printf("%.3s\n", "abcdefg");
	ft_printf("%.3s\n\n\n", "abcdefg");

	printf("flag -\n");
	printf("%-10d|\n", 42);
	ft_printf("%-10d|\n\n\n", 42);
	
	printf("flag #\n");
	printf("%#x\n", 42);
	ft_printf("%#x\n\n", 42);
	printf("%#X\n", 42);
	ft_printf("%#X\n\n\n", 42);

	printf("flag ' '\n");
	printf("|% d|\n", 42);
	ft_printf("|% d|\n\n", 42);
	printf("|% d|\n", -42);
	ft_printf("|% d|\n\n", -42);
	printf("|% i|\n", 42);
	ft_printf("|% i|\n\n", 42);
	printf("|% i|\n", -42);
	ft_printf("|% i|\n\n\n", -42);

	printf("flag +\n");
	printf("%+d\n", 42);
	ft_printf("%+d\n\n", 42);
	printf("%+d\n", 0);
	ft_printf("%+d\n\n", 0);
	printf("%+d\n", -10);
	ft_printf("%+d\n\n", -10);


	return (0);
}
