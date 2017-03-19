# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 16:49:11 by dburtnja          #+#    #+#              #
#    Updated: 2017/03/15 15:19:56 by dburtnja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a

NAME = ./resources/players/filler #change to ./
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =	main.c\
        read_map.c\
        find_coordinates.c\
        find_hostile.c\
        read_tokens.c\
        find_place.c\
        help_find_place.c

OBJ = $(SRC:.c=.o)

all:	$(LIB) $(NAME)

$(LIB):
		make -C ./libft

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)
%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<

clean:
		@make clean -C ./libft
		@rm -f $(OBJ)

fclean:
		@make fclean -C ./libft
		@make clean
		@rm -f $(NAME)
re:
		@make fclean
		@make all
