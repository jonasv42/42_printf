# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvets <jvets@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 17:41:05 by jvets             #+#    #+#              #
#    Updated: 2023/09/11 17:52:52 by jvets            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c ft_printf_utils.c ft_putnbr.c
FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
OBJECTS_DIR = obj
OBJECTS = obj/ft_printf.o obj/ft_printf_utils.o obj/ft_putnbr.o

all: $(NAME)

$(OBJECTS_DIR)/%.o: %.c
	mkdir -p $(OBJECTS_DIR)
	cc $(FLAGS) -c $< -o $@ -I ft_printf.h

$(OBJECTS): $(OBJECTS_DIR)/%.o: %.c
	mkdir -p $(OBJECTS_DIR)
	cc $(FLAGS) -c $< -o $@ -I ft_printf.h

$(NAME): $(OBJECTS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJECTS)

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJECTS_DIR)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
