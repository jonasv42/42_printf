/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:53:07 by jvets             #+#    #+#             */
/*   Updated: 2023/09/10 13:48:39 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(const char ***str, va_list ap, int **c);
void	id_specifier(const char **str, va_list ap, int *c);
void	print_str(va_list ap, int **c);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	c;

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
	while (*str[i] && !ft_strchr("cs", *str[i]))
		i++;
	if (*str[i] == 'c')
		print_char(&str, ap, &c);
	else if (*str[i] == 's')
		print_str(ap, &c);
}

void	print_str(va_list ap, int **c)
{
	char *str_to_print;

	str_to_print = va_arg(ap, char *);
	while (/*str_to_print != NULL && */*str_to_print)
	{
		**c += write(1, str_to_print, 1);
		str_to_print++;
	}
}

void	print_char(const char ***str, va_list ap, int **c)
{
	int	character;

	if (***str == 'c')
	{
		character = va_arg(ap, int);
		**c += write(1, &character, 1);
	}
		
}
