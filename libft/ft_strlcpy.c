/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:58:53 by jvets             #+#    #+#             */
/*   Updated: 2023/08/08 16:26:21 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	return_value;

	i = 0;
	return_value = ft_strlen(src);
	if (size == 0)
		return (return_value);
	while (i++ < size - 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (return_value);
}
