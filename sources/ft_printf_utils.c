/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:43:37 by jvets             #+#    #+#             */
/*   Updated: 2023/09/18 16:01:55 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_str(va_list ap, int **c)
{
	char	*str_to_print;

	str_to_print = va_arg(ap, char *);
	if (str_to_print == NULL)
	{
		**c += write(1, "(null)", 6);
		return ;
	}
	while (*str_to_print)
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

void	print_u(unsigned int i, int **c)
{
	if (i < 0)
		return ;
	ft_put_unsigned_nbr(i);
	if (i == 0)
		(**c)++;
	while (i)
	{
		i = i / 10;
		(**c)++;
	}
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

void	print_p(va_list ap, int **c)
{
	unsigned long	ptr_addr;

	ptr_addr = (unsigned long)va_arg(ap, void *);
	if (ptr_addr == 0)
	{
		**c += write(1, "(nil)", 5);
		return ;
	}
	**c += write(1, "0x", 2);
	print_hexadec(ptr_addr, LOWER_CASE);
	while (ptr_addr > 0)
	{
		ptr_addr /= 16;
		(**c)++;
	}
}
