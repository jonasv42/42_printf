/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:53:07 by jvets             #+#    #+#             */
/*   Updated: 2023/09/11 17:59:28 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		c;

	va_start(ap, str);
	c = 0;
	if (str == NULL)
		return (-1);
	while (*str)
	{
		if (*str == '%' && str[1] != '%')
			id_specifier(&str, ap, &c);
		else
			c += write(1, str, 1);
		if (*str == '%' && str[1] == '%')
			str++;
		str++;
	}
	va_end(ap);
	return (c);
}

void	id_specifier(const char **str, va_list ap, int *c)
{
	int	i;

	i = 0;
	(*str)++;
	while (*str[i] && !ft_strchr("csidpuxX", *str[i]))
		i++;
	if (*str[i] == 'c')
		print_char(&str, ap, &c);
	else if (*str[i] == 's')
		print_str(ap, &c);
	else if (*str[i] == 'i' || *str[i] == 'd')
		print_i(va_arg(ap, int), &c);
	else if (*str[i] == 'p')
		print_p(ap, &c);
	else if (*str[i] == 'u')
		print_u(va_arg(ap, unsigned int), &c);
	else if (*str[i] == 'x')
		print_x(va_arg(ap, unsigned int), &c, LOWER_CASE);
	else if (*str[i] == 'X')
		print_x(va_arg(ap, unsigned int), &c, UPPER_CASE);
}

void	print_x(unsigned int n, int **c, int case_)
{
	print_hexadec(n, case_);
	if (n == 0)
		(**c)++;
	while (n > 0)
	{
		n /= 16;
		(**c)++;
	}
}

void	print_hexadec(unsigned long n, int case_)
{
	char	*symbols;

	if (case_ == LOWER_CASE)
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (n < 16)
		write(1, &symbols[n], 1);
	else
	{
		print_hexadec(n / 16, case_);
		print_hexadec(n % 16, case_);
	}
}
