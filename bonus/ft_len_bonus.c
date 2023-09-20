/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:00:42 by jvets             #+#    #+#             */
/*   Updated: 2023/09/19 21:01:39 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	get_ptr_len(unsigned long aux, int *len)
{
	while (aux > 0)
	{
		aux /= 16;
		(*len)++;
	}
	return (*len);
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
