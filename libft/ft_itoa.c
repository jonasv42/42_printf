/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:59:27 by jvets             #+#    #+#             */
/*   Updated: 2023/08/12 18:43:34 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static char	*int_to_str(char *s, long int nbr, int *i)
{
	if (nbr == 0)
		s[0] = '0';
	while (nbr)
	{
		s[(*i)--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	int			i;
	char		*s;

	nbr = n;
	i = int_len(nbr);
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	s[i--] = '\0';
	if (nbr < 0)
	{
		s[0] = '-';
		nbr *= -1;
	}
	int_to_str(s, nbr, &i);
	return (s);
}
