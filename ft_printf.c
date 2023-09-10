/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:53:07 by jvets             #+#    #+#             */
/*   Updated: 2023/09/10 18:33:33 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(const char ***str, va_list ap, int **c);
void	id_specifier(const char **str, va_list ap, int *c);
void	print_str(va_list ap, int **c);
void	print_i(int i, int **c);
void	ft_putnbr(int nb);
void	print_p(va_list ap, int **c);
void	print_hexadec(unsigned long n, int case_);
void	print_x(unsigned int n, int **c, int case_);

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
		print_i(va_arg(ap, unsigned int), &c);
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

void	print_p(va_list ap, int **c)
{
	unsigned long	ptr_addr;
	ptr_addr = (unsigned long)va_arg(ap, void *);
	**c += write(1, "0x", 2);
	print_hexadec(ptr_addr, LOWER_CASE);
	while (ptr_addr > 0)
	{
		ptr_addr /= 16;
		(**c)++;
	}
}

void	ft_putnbr(int nb)
{
	char c;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	print_i(int i, int **c)
{
	ft_putnbr(i);
	if (i <= 0)
	{
		i *= -1;
		(**c)++;
	}
	while (i)
	{
		i = i / 10;
		(**c)++;
	}
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
