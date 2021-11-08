# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsaada <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 17:21:35 by dsaada            #+#    #+#              #
#    Updated: 2021/11/08 18:22:11 by dsaada           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAGS = -Werror -Wextra -Wextra

RL_FLAGS = -L/usr/local/lib -I/usr/local/include -lreadline

SRC = ./src/main.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -lreadline -c $< -o $@

$(NAME): $(OBJ) ./src/minishell.h
	$(CC) $(OBJ) $(RL_FLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f ./src/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
