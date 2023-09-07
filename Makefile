# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvets <jvets@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 17:41:05 by jvets             #+#    #+#              #
#    Updated: 2023/09/06 22:53:35 by jvets            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c
FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJECTS)

$(LIBFT):
	make -C libft

./obj/%.o: %.c ft_printf.h
	mkdir -p ./obj/
	cc $(FLAGS) -c $< -o $@

clean:
	rm -rf ./obj/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
