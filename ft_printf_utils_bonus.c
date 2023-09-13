/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:43:37 by jvets             #+#    #+#             */
/*   Updated: 2023/09/13 17:34:11 by jvets            ###   ########.fr       */
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
	if (flag_ids.precision == 0)
	{
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
	else
	{
		while (*str_to_print && flag_ids.min_len-- > 0)
		{
			**c += write(1, str_to_print, 1);
			str_to_print++;
		}
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

void	print_u(unsigned int i, int **c, p_flag flag_ids)
{
	int		len;
	unsigned int	aux;

	len = 0;
	aux = i;
	if (i < 0)
		return ;
	if (i == 0)
		len++;
	while (i)
	{
		i = i / 10;
		len++;
	}
	**c += len;
	while (flag_ids.min_len > len && flag_ids.align_left == 0)
	{
		if (flag_ids.zero == 1)
			**c += write(1, "0", 1);
		else
			**c += write(1, " ", 1);
		flag_ids.min_len--;
	}
	ft_put_unsigned_nbr(aux);
	while (flag_ids.min_len-- > len && flag_ids.align_left == 1)
		**c += write(1, " ", 1);
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
	//if (flag_ids.precision == 0)
	//{
		**c += len;
		len_dif = (flag_ids.min_len - len);
		if (flag_ids.precision == 1 && i < 0)
			len_dif++; // added b/c %.2i -1 resulted in -1 and not -01
		while (len_dif > 0 && flag_ids.align_left == 0)
		{
			if (flag_ids.zero == 1 || flag_ids.precision == 1)
			{
				if (i < 0)
				{
					write(1, "-", 1);
					i *= -1;
				}
				**c += write(1, "0", 1);
			}
			else
				**c += write(1, " ", 1);
			len_dif--;
		}
		ft_putnbr(i);
		while (len_dif-- > 0 && flag_ids.align_left == 1)
			**c += write(1, " ", 1);
	//}
	/*else
	{
		len_dif = flag_ids.min_len - len;
		while (len_dif++ < 0)
		{
			i /= 10;
			(**c)++;
		}
		ft_putnbr(i);
	}*/
}

void	print_p(va_list ap, int **c, p_flag flag_ids)
{
	unsigned long	ptr_addr;
	unsigned long	aux;
	int		len;

	ptr_addr = (unsigned long)va_arg(ap, void *);
	aux = ptr_addr;
	len = 0;
	if (ptr_addr == 0)
	{
		**c += write(1, "(nil)", 5);
		return ;
	}
	while (aux > 0)
	{
		aux /= 16;
		len++;
	}
	**c += len;
	while (flag_ids.min_len > (len + 2) && flag_ids.align_left == 0)
	{
		**c += write(1, " ", 1);
		flag_ids.min_len--;
	}
	**c += write(1, "0x", 2);
	print_hexadec(ptr_addr, LOWER_CASE);
	while (flag_ids.min_len > (len + 2) && flag_ids.align_left == 1)
	{
		**c += write(1, " ", 1);
		flag_ids.min_len--;
	}
}
