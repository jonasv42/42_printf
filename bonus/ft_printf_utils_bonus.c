/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:43:37 by jvets             #+#    #+#             */
/*   Updated: 2023/09/19 19:48:11 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	print_str(va_list ap, int **c, t_flag flag_ids)
{
	char		*str_to_print;

	str_to_print = va_arg(ap, char *);
	if (str_to_print == NULL)
	{
		if (flag_ids.min_len >= 6 || flag_ids.min_len == 0)
			**c += write(1, "(null)", 6);
		return ;
	}
	if (flag_ids.precision == 0)
		**c += print_str_no_precision(&flag_ids, &str_to_print);
	else
	{
		while (*str_to_print && flag_ids.min_len-- > 0)
		{
			**c += write(1, str_to_print, 1);
			str_to_print++;
		}
	}	
}

int	print_str_no_precision(t_flag *flag_ids, char **str_to_print)
{
	long int	len_dif;
	int			c;

	c = 0;
	len_dif = (flag_ids->min_len - ft_strlen(*str_to_print));
	while (len_dif > 0 && (flag_ids->align_left == 0 || flag_ids->space == 1))
	{
		c += write(1, " ", 1);
		len_dif--;
	}	
	while (**str_to_print)
	{
		c += write(1, *str_to_print, 1);
		(*str_to_print)++;
	}
	while (len_dif > 0 && flag_ids->align_left == 1)
	{
		c += write(1, " ", 1);
		len_dif--;
	}
	return (c);
}

void	print_char(va_list ap, int **c, t_flag flag_ids)
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

void	print_u(unsigned int i, int **c, t_flag flag_ids)
{
	int				len;
	unsigned int	aux;

	aux = i;
	if (i < 0)
		return ;
	len = get_len(i);
	while (flag_ids.min_len > len && (flag_ids.align_left == 0 || flag_ids.precision == 1))
	{
		if (flag_ids.zero == 1 || flag_ids.precision == 1)
			**c += write(1, "0", 1);
		else
			**c += write(1, " ", 1);
		flag_ids.min_len--;
	}
	if (!(flag_ids.precision == 1 && flag_ids.min_len == 0 && aux == 0))
	{
		ft_put_unsigned_nbr(aux);
		**c += len;
	}
	while (flag_ids.min_len-- > len && flag_ids.align_left == 1)
		**c += write(1, " ", 1);
}

int	get_len(unsigned int i)
{
	int	len;

	len = 0;
	if (i == 0)
		len++;
	while (i)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

void	get_length(long long int aux, int *len)
{
	*len = 0;
	if (aux <= 0)
	{
		aux *= -1;
		(*len)++;
	}
	while (aux)
	{
		aux = aux / 10;
		(*len)++;
	}
}

int	format_zeros_precision(t_flag *flag_ids, long long int *aux, int *ran_once, int i)
{
	int	c;

	c = 0;
	if (*aux < 0)
	{
		write(1, "-", 1);
		*aux *= -1;
	}
	if ((*ran_once)++ == 0 && flag_ids->plus == 1 && i >= 0)
	{
		c += write(1, "+", 1);
		flag_ids->plus = 2;
	}
	else
		c += write(1, "0", 1);
	return (c);
}

void	print_i(int i, int **c, t_flag flag_ids)
{
	int				len;
	long long int	aux;
	int				len_dif;
	int				ran_once;

	aux = (long long int)i;
	ran_once = 0;
	get_length(aux, &len);
	len_dif = (flag_ids.min_len - len);
	if (flag_ids.precision == 1 && aux < 0)
		len_dif++;
	while (len_dif > 0 && flag_ids.align_left == 0)
	{
		if (flag_ids.zero == 1 || flag_ids.precision == 1)
			**c += format_zeros_precision(&flag_ids, &aux, &ran_once, i);
		else
		{
			if (len_dif == 1 && flag_ids.plus == 1 && i >= 0)
			{
				**c += write(1, "+", 1);
				flag_ids.plus = 2;
			}
			else
				**c += write(1, " ", 1);
		}
		len_dif--;
	}
	if (flag_ids.plus == 1 && aux >= 0)
		**c += write(1, "+", 1);
	if (flag_ids.space == 1 && flag_ids.plus < 1 && aux >= 0)
		**c += write(1, " ", 1);
	if (i == INT_MIN && flag_ids.precision == 1 && flag_ids.min_len >= len)
	{
		ft_put_unsigned_nbr((unsigned int)aux);
		**c += len;
	}
	else if (!(flag_ids.precision == 1 && flag_ids.min_len == 0 && aux == 0))
	{
		ft_putnbr(aux);
		**c += len;
	}
	while (len_dif-- > 0 && flag_ids.align_left == 1)
		**c += write(1, " ", 1);
}

void	print_p(va_list ap, int **c, t_flag flag_ids)
{
	unsigned long	ptr_addr;
	unsigned long	aux;
	int				len;

	ptr_addr = (unsigned long)va_arg(ap, void *);
	aux = ptr_addr;
	len = 0;
	if (ptr_addr == 0)
	{
		**c += write(1, "(nil)", 5);
		return ;
	}
	**c += get_ptr_len(aux, &len);
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

int	get_ptr_len(unsigned long aux, int *len)
{
	while (aux > 0)
	{
		aux /= 16;
		(*len)++;
	}
	return (*len);
}
