# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvets <jvets@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 17:41:05 by jvets             #+#    #+#              #
#    Updated: 2023/09/12 18:14:07 by jvets            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c ft_printf_utils.c ft_putnbr.c
FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
OBJ_DIR = obj
OBJECTS = obj/ft_printf.o obj/ft_printf_utils.o obj/ft_putnbr.o
BONUS_SOURCES = ft_printf_bonus.c ft_printf_utils_bonus.c ft_putnbr_bonus.c
BONUS_OBJECTS = ft_printf_bonus.o ft_printf_utils_bonus.o ft_putnbr_bonus.o
BONUS_OBJ_DIR = bonus-obj

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	cc $(FLAGS) -c $< -o $@ -I ft_printf.h

$(NAME): $(OBJECTS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $^

$(LIBFT):
	make -C libft

bonus: $(LIBFT) $(BONUS_OBJECTS)
	make OBJECTS="$(BONUS_OBJECTS)"

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SOURCES)
	mkdir -p $(BONUS_OBJ_DIR)
	cc $(FLAGS) -c $< -o $@ -I ft_printf_bonus.h

main: bonus
	cc -g3 $(FLAGS) main.c $(BONUS_SOURCES) ft_printf_bonus.h libftprintf.a
clean:
	rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all bonus main clean fclean re
