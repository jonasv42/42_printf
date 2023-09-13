/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:16:31 by jvets             #+#    #+#             */
/*   Updated: 2023/09/12 22:53:07 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define LOWER_CASE 0
# define UPPER_CASE 1

typedef struct p_flags {
	int	align_left;
	int	min_len;
	int	zero;
	int	precision;
}	p_flag;

int		ft_printf(const char *str, ...);
void	print_char(va_list ap, int **c, p_flag flag_ids);
void	print_str(va_list ap, int **c, p_flag flag_ids);
void	print_i(int i, int **c, p_flag flag_ids);
void	ft_putnbr(int nb);
void	print_p(va_list ap, int **c, p_flag flag_ids);
void	print_u(unsigned int i, int **c, p_flag flag_ids);
void	ft_put_unsigned_nbr(unsigned int nb);
void	id_specifier(const char **str, va_list ap, int *c);
void	print_x(unsigned int n, int **c, int case_, p_flag flag_ids);
void	print_hexadec(unsigned long n, int case_);
p_flag	process_flags(char *flags);

#endif
