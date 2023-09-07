/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:53:07 by jvets             #+#    #+#             */
/*   Updated: 2023/09/07 15:57:44 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(const char *str, va_list ap);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	c;

	va_start(ap, str);
	c = 0;
	while (*str)
	{
		if (*str == '%')
			print_format(++str, ap);
		else
			c += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (c);
}

void	print_format(const char *str, va_list ap)
{
	int	character;

	if (*str == 'c')
	{
		character = va_arg(ap, int);
		write(1, &character, 1);
	}
		
}
