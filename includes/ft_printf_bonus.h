/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:16:31 by jvets             #+#    #+#             */
/*   Updated: 2023/09/19 19:48:43 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

# define LOWER_CASE 0
# define UPPER_CASE 1
# define INT_MIN -2147483648

typedef struct t_flags {
	int	align_left;
	int	min_len;
	int	zero;
	int	precision;
	int	sharp;
	int	space;
	int	plus;
}	t_flag;

int		ft_printf(const char *str, ...);
void	print_char(va_list ap, int **c, t_flag flag_ids);
void	print_str(va_list ap, int **c, t_flag flag_ids);
void	print_i(int i, int **c, t_flag flag_ids);
void	ft_putnbr(int nb);
void	print_p(va_list ap, int **c, t_flag flag_ids);
void	print_u(unsigned int i, int **c, t_flag flag_ids);
void	ft_put_unsigned_nbr(unsigned int nb);
void	id_specifier(const char **str, va_list ap, int *c);
void	print_x(unsigned int n, int **c, int case_, t_flag flag_ids);
void	print_hexadec(unsigned long n, int case_);
t_flag	process_flags(char *flags);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	fill_struct(char **flags, t_flag *flag_ids);
int		print_prefix(t_flag *flag_ids, unsigned int *aux, int *len, int case_);
int		print_str_no_precision(t_flag *flag_ids, char **str_to_print);
int		get_len(unsigned int i);
int		get_ptr_len(unsigned long aux, int *len);
void	get_length(long long int aux, int *len);
int		format_zeros_precision(t_flag *flag_ids, long long int *aux, int *ran_once, int i);

#endif
