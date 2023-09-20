/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:56:01 by jvets             #+#    #+#             */
/*   Updated: 2023/09/19 21:17:38 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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
			**c += format_z_p(&flag_ids, &aux, &ran_once, i);
		else
			**c += format_plus(len_dif, &flag_ids, i);
		len_dif--;
	}
	if (flag_ids.plus == 1 && aux >= 0)
		**c += write(1, "+", 1);
	if (flag_ids.space == 1 && flag_ids.plus < 1 && aux >= 0)
		**c += write(1, " ", 1);
	**c += choose_putnbr(i, flag_ids, len, aux);
	**c += write_spaces(len_dif, flag_ids);
}

int	write_spaces(int len_dif, t_flag flag_ids)
{
	int	c;

	c = 0;
	while (len_dif-- > 0 && flag_ids.align_left == 1)
	c += write(1, " ", 1);
	return (c);
}

int	choose_putnbr(int i, t_flag flag_ids, int len, long long int aux)
{
	int	c;

	c = 0;
	if (i == INT_MIN && flag_ids.precision == 1 && flag_ids.min_len >= len)
	{
		ft_put_unsigned_nbr((unsigned int)aux);
		c += len;
	}
	else if (!(flag_ids.precision == 1 && flag_ids.min_len == 0 && aux == 0))
	{
		ft_putnbr(aux);
		c += len;
	}
	return (c);
}

int	format_z_p(t_flag *flag_ids, long long int *aux, int *ran_once, int i)
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

int	format_plus(int len_dif, t_flag *flag_ids, int i)
{
	int	c;

	c = 0;
	if (len_dif == 1 && flag_ids->plus == 1 && i >= 0)
	{
		c += write(1, "+", 1);
		flag_ids->plus = 2;
	}
	else
		c += write(1, " ", 1);
	return (c);
}
