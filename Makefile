# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvets <jvets@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 17:41:05 by jvets             #+#    #+#              #
#    Updated: 2023/09/20 16:55:46 by jvets            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBS		=	-lft
INCLUDES	=	-I ./includes
CFLAGS		=	-Wall -Wextra -Werror -g3 $(INCLUDES)
FILES		=	ft_printf.c ft_putnbr.c ft_printf_utils.c ft_strchr.c ft_strlen.c \
				ft_substr.c ft_atoi.c
FILESB		=	ft_printf_bonus.c ft_putnbr_bonus.c ft_printf_utils_bonus.c \
				ft_strchr_bonus.c ft_strlen_bonus.c ft_substr_bonus.c \
				ft_atoi_bonus.c ft_print_i_bonus.c ft_print_hexadec_bonus.c \
				ft_len_bonus.c
SRCS		=	$(addprefix sources/, $(FILES))
BSRCS		=	$(addprefix bonus/, $(FILESB))
OBJS		=	$(SRCS:.c=.o)
BOBJ		=	$(BSRCS:.c=.o)
AR			=	ar -rcs
CC			=	cc

all: $(NAME)

$(NAME): $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@

bonus: $(BOBJ)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

cleanbonus: 
	rm -f $(BOBJ)

fcleanbonus: cleanbonus fclean

rebonus: fcleanbonus bonus 

re: fclean all

test: bonus
	$(CC) $(CFLAGS) test.c $(BSRCS) $(INCLUDES)

.PHONY: all bonus clean fclean cleanbonus fcleanbonus rebonus re