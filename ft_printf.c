/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:53:07 by jvets             #+#    #+#             */
/*   Updated: 2023/09/07 21:10:36 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(const char **str, va_list ap, int *c);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	c;

	va_start(ap, str);
	c = 0;
	while (*str)
	{
		if (*str == '%' && str[1] != '%')
			print_format(&str, ap, &c);
		else
			c += write(1, str, 1);
		if (*str == '%' && str[1] == '%')
			str++;
		str++;
	}
	va_end(ap);
	return (c);
}

void	print_format(const char **str, va_list ap, int *c)
{
	int	character;

	(*str)++;
	if (**str == 'c')
	{
		character = va_arg(ap, int);
		*c += write(1, &character, 1);
	}
		
}
