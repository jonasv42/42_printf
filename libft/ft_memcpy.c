/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:32:26 by jvets             #+#    #+#             */
/*   Updated: 2023/08/12 15:25:37 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*destination;
	char	*source;

	if (!dest && !src)
		return (dest);
	destination = (char *)dest;
	source = (char *)src;
	while (n-- > 0)
		destination[n] = source[n];
	return (destination);
}
