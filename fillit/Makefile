# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maseidua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 15:29:14 by maseidua          #+#    #+#              #
#    Updated: 2018/12/01 13:36:49 by maseidua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRC = main.c fillit.c valid_test.c extra_func.c
HDR = fillit.h
LIB = libft/libft.a
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	make re -C libft
	gcc $(FLAGS) -c $(SRC) -I $(HDR) 
	gcc $(FLAGS) $(LIB) -o $(NAME) $(SRC)
	
clean:
	/bin/rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
