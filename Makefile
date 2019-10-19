#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vopolonc <vopolonc@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 16:57:32 by vopolonc          #+#    #+#              #
#    Updated: 2019/04/06 12:48:54 by vopolonc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol
CC = gcc -Wall -Wextra -Werror 
SRC = main.c fractols_mandatory.c initializing.c drawer.c hooker.c fractols_secondly.c
OBJ := $(SRC:%.c=%.o)
HEAD = fractol.h
LIB = -C libft

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	@make $(LIB)
	$(CC) -I $(HEAD) -L libft/ -lft -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)
	@make clean $(LIB)

fclean: clean
	rm -f $(NAME)
	@make fclean $(LIB)

re: fclean all
