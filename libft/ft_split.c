/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:41:25 by jvets             #+#    #+#             */
/*   Updated: 2023/08/11 16:33:54 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_parts(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

static int	count_chars(char const *s, char c)
{
	int	chars_count;

	chars_count = 0;
	while (*s != c && *s)
	{
		s++;
		chars_count++;
	}
	return (chars_count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		parts;
	int		chars_count;
	int		i;

	parts = check_parts(s, c);
	str = malloc(sizeof(char *) * (parts + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			chars_count = count_chars(s, c);
			str[i] = ft_substr(s, 0, chars_count);
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	str[i] = NULL;
	return (str);
}
