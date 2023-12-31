/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:53:07 by jvets             #+#    #+#             */
/*   Updated: 2023/09/20 19:20:08 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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
	int		i;
	t_flag	flag_ids;

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

t_flag	process_flags(char *flags)
{
	int		i;
	char	*ptr_to_free;
	t_flag	flag_ids;

	i = 0;
	flag_ids.align_left = 0;
	flag_ids.min_len = 0;
	flag_ids.zero = 0;
	flag_ids.precision = 0;
	flag_ids.sharp = 0;
	flag_ids.space = 0;
	flag_ids.plus = 0;
	ptr_to_free = flags;
	fill_struct(&flags, &flag_ids);
	flag_ids.min_len = ft_atoi(flags);
	free(ptr_to_free);
	return (flag_ids);
}

void	fill_struct(char **flags, t_flag *flag_ids)
{
	while (**flags && (((**flags) < '1') || ((**flags) > '9')))
	{
		if ((**flags) == '-')
			flag_ids->align_left = 1;
		if ((**flags) == '0')
			flag_ids->zero = 1;
		if ((**flags) == '.')
			flag_ids->precision = 1;
		if ((**flags) == '#')
			flag_ids->sharp = 1;
		if ((**flags) == ' ')
			flag_ids->space = 1;
		if ((**flags) == '+')
		{
			flag_ids->plus = 1;
			flag_ids->space = 1;
		}
		(*flags)++;
	}
}
