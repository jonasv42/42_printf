/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:07:08 by jvets             #+#    #+#             */
/*   Updated: 2023/08/08 16:34:31 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	convert_numbers(const char *nptr, int *result)
{
	while (*nptr >= '0' && *nptr <= '9')
	{
		*result = (*result * 10) + (*nptr - '0');
		nptr++;
	}
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*nptr)
	{
		if (*nptr == ' ' || (*nptr > 8 && *nptr < 14))
			nptr++;
		else if (*nptr == '-' || *nptr == '+')
		{
			if (nptr[1] < '0' || nptr[1] > '9')
				return (0);
			if (*nptr == '-')
				sign = -1;
			nptr++;
		}
		else
		{
			convert_numbers(nptr, &result);
			return (result * sign);
		}
	}
	return (0);
}
