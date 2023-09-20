/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadec_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:20:19 by jvets             #+#    #+#             */
/*   Updated: 2023/09/19 21:21:26 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	print_x(unsigned int n, int **c, int case_, t_flag flag_ids)
{
	unsigned int	aux;
	int				len;

	aux = n;
	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	**c += print_prefix(&flag_ids, &aux, &len, case_);
	if (!(flag_ids.precision == 1 && flag_ids.min_len == 0 && aux == 0))
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

int	print_prefix(t_flag *flag_ids, unsigned int *aux, int *len, int case_)
{
	int	c;

	c = 0;
	while (flag_ids->min_len > *len && (flag_ids->align_left == 0
			|| flag_ids->precision == 1))
	{
		if (flag_ids->zero == 1 || flag_ids->precision == 1)
			c += write(1, "0", 1);
		else
			c += write(1, " ", 1);
		flag_ids->min_len--;
	}
	if (flag_ids->sharp == 1 && *aux != 0)
	{
		if (case_ == LOWER_CASE)
			c += write(1, "0x", 2);
		else
			c += write(1, "0X", 2);
	}
	return (c);
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
