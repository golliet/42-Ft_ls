# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: golliet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 15:26:08 by golliet           #+#    #+#              #
#    Updated: 2018/01/16 11:45:58 by golliet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ft_ls

SRC = ft_ls.c list.c sort.c parse.c print.c color.c ft_error.c misc.c parsebis.c listbis.c listter.c printbis.c printter.c printqua.c

OBJ = $(SRC:.c=.o)

INCLUDE = ft_ls.h color.h

SAN = -g3 -fsanitize=address

FLAG = -Werror -Wextra -Wall

all: $(NAME)

debug : $(OBJ)
	make -C libft/
	gcc -o $(NAME) $(SAN) $(FLAG) $(OBJ) libft/libft.a

$(NAME) : $(OBJ)
	make -C libft/
	gcc -o $(NAME) $(FLAG) $(OBJ) libft/libft.a

clean :
	rm -f $(OBJ)
	make clean -C libft/

fclean :
	rm -f $(OBJ)
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all
