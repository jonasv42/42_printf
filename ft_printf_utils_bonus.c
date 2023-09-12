/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:43:37 by jvets             #+#    #+#             */
/*   Updated: 2023/09/12 17:43:31 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_str(va_list ap, int **c, p_flag flag_ids)
{
	char	*str_to_print;
	long int	len_dif;

	str_to_print = va_arg(ap, char *);
	if (str_to_print == NULL)
	{
		**c += write(1, "(null)", 6);
		return ;
	}
	len_dif = (flag_ids.min_len - ft_strlen(str_to_print));
	while (len_dif > 0 && flag_ids.align_left == 0)
	{
		**c += write(1, " ", 1);
		len_dif--;
	}	
	while (*str_to_print)
	{
		**c += write(1, str_to_print, 1);
		str_to_print++;
	}
	while (len_dif > 0 && flag_ids.align_left == 1)
	{
		**c += write(1, " ", 1);	
		len_dif--;
	}	
}

void	print_char(va_list ap, int **c, p_flag flag_ids)
{
	int	character;

	character = va_arg(ap, int);
	if (flag_ids.align_left == 1)
		**c += write(1, &character, 1);
	while (--flag_ids.min_len > 0)
		**c += write(1, " ", 1);
	if (flag_ids.align_left == 0)
		**c += write(1, &character, 1);
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

void	print_i(int i, int **c, p_flag flag_ids)
{
	int 	len;
	int	aux;
	int	len_dif;

	len = 0;
	aux = i;
	if (aux <= 0)
	{
		aux *= -1;
		len++;
	}
	while (aux)
	{
		aux = aux / 10;
		len++;
	}
	**c += len;
	len_dif = (flag_ids.min_len - len);
	while (len_dif > 0 && flag_ids.align_left == 0)
	{
		**c += write(1, " ", 1);
		len_dif--;
	}
	ft_putnbr(i);
	while (len_dif-- > 0 && flag_ids.align_left == 1)
		**c += write(1, " ", 1);
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
