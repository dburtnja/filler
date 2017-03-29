# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 16:49:11 by dburtnja          #+#    #+#              #
#    Updated: 2017/03/20 21:43:32 by dburtnja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a

NAME = filler
BONUS = bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =	main.c\
        read_map.c\
        find_coordinates.c\
        find_hostile.c\
        read_tokens.c\
        find_place.c\
		free_mem.c\
        help_find_place.c

B_SRC = bonus_dir/check_flag.c\
        bonus_dir/out_filler.c\
        bonus_dir/read_input.c

OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

all:	$(LIB) $(NAME) $(BONUS)

$(LIB):
		make -C ./libft

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)
%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<

$(BONUS): $(B_OBJ)
		@$(CC) $(CFLAGS) $(B_OBJ) -o $(BONUS) $(LIB)
%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<


clean:
		@make clean -C ./libft
		@rm -f $(OBJ)
		@rm -f $(B_OBJ)

fclean:
		@make fclean -C ./libft
		@make clean
		@rm -f $(NAME)
		@rm -f $(BONUS)

re:
		@make fclean
		@make all
