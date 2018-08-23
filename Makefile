# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmostert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 10:52:24 by nmostert          #+#    #+#              #
#    Updated: 2018/08/23 10:02:29 by nmostert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=rescources/players/filler
CC=gcc
CFLAGS=-Wall -Wextra -Werror -c -I.
CFILES=place.c \
	   trim.c \
	   main.c \

OBJ=$(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(CFLAGS) $(OBJ) libft/libft.a
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
