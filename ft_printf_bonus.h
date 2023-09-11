/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:16:31 by jvets             #+#    #+#             */
/*   Updated: 2023/09/11 20:33:39 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define LOWER_CASE 0
# define UPPER_CASE 1

int		ft_printf(const char *str, ...);
void	print_char(const char ***str, va_list ap, int **c);
void	print_str(va_list ap, int **c);
void	print_i(int i, int **c);
void	ft_putnbr(int nb);
void	print_p(va_list ap, int **c);
void	print_u(unsigned int i, int **c);
void	ft_put_unsigned_nbr(unsigned int nb);
void	id_specifier(const char **str, va_list ap, int *c);
void	print_x(unsigned int n, int **c, int case_);
void	print_hexadec(unsigned long n, int case_);
void	process_flags(char *flags);

#endif
