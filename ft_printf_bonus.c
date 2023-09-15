/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:53:07 by jvets             #+#    #+#             */
/*   Updated: 2023/09/15 18:47:52 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
	p_flag	flag_ids;

	i = 0;
	(*str)++;
	while ((*str)[i] && !ft_strchr("csidpuxX", (*str)[i]))
		i++;
	flag_ids = process_flags(ft_substr(*str, 0, i));
	(*str) += i;
	if ((*str)[0] == 'c')
		print_char(ap, &c, flag_ids);
	else if ((*str)[0] == 's')
		print_str(ap, &c, flag_ids);
	else if ((*str)[0] == 'i' || *str[0] == 'd')
		print_i(va_arg(ap, int), &c, flag_ids);
	else if ((*str)[0] == 'p')
		print_p(ap, &c, flag_ids);
	else if ((*str)[0] == 'u')
		print_u(va_arg(ap, unsigned int), &c, flag_ids);
	else if ((*str)[0] == 'x')
		print_x(va_arg(ap, unsigned int), &c, LOWER_CASE, flag_ids);
	else if ((*str)[0] == 'X')
		print_x(va_arg(ap, unsigned int), &c, UPPER_CASE, flag_ids);
}

p_flag	process_flags(char *flags)
{
	int	i;
	char	*ptr_to_free;
	p_flag	flag_ids;

	i = 0;
	flag_ids.align_left = 0;
	flag_ids.min_len = 0;
	flag_ids.zero = 0;
	flag_ids.precision = 0;
	flag_ids.sharp = 0;
	flag_ids.space = 0;
	flag_ids.plus = 0;
	ptr_to_free = flags;
	while (*flags && (((*flags) < '1') || ((*flags) > '9')))
	{
		if ((*flags) == '-')
			flag_ids.align_left = 1;
		if ((*flags) == '0')
			flag_ids.zero = 1;
		if ((*flags) == '.') // what about interaction with 0?
			flag_ids.precision = 1;
		if ((*flags) == '#')
			flag_ids.sharp = 1;
		if ((*flags) == ' ')
			flag_ids.space = 1;
		if ((*flags) == '+')
		{
			flag_ids.plus = 1;
			flag_ids.space = 1;
		}
		flags++;
	}
	flag_ids.min_len = ft_atoi(flags); // change name of min_len to include precision
	free(ptr_to_free);
	return (flag_ids);
}

void	print_x(unsigned int n, int **c, int case_, p_flag flag_ids)
{
	unsigned int	aux;
	int		len;

	aux = n;
	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	while (flag_ids.min_len > len && (flag_ids.align_left == 0 || flag_ids.precision == 1))
	{
		if (flag_ids.zero == 1 || flag_ids.precision == 1)
			**c += write(1, "0", 1);
		else
			**c += write(1, " ", 1);
		flag_ids.min_len--;
	}
	if (flag_ids.sharp == 1 && aux != 0)
	{
		if (case_ == LOWER_CASE)
			**c += write(1, "0x", 2);
		else
			**c += write(1, "0X", 2);
	}
	if (!(flag_ids.precision == 1 && flag_ids.min_len == 0 && aux == 0)) +14 tests
	{
	print_hexadec(aux, case_);
	**c += len;
	}
	while (flag_ids.min_len > len && flag_ids.align_left == 1)
	{
		**c += write(1, " ", 1);
		flag_ids.min_len--;
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
