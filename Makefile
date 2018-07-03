# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 16:52:36 by vsarapin          #+#    #+#              #
#    Updated: 2017/12/05 16:54:35 by vsarapin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC		= ./main.c  \
		  ./move.c  \
		  ./readwrite.c   \
		  ./square.c \
		  ./validandmemory.c \
		  ./ft_putchar.c \
		  ./ft_putstr.c \
		  ./ft_strsub.c \
		  ./ft_strlen.c \
		  ./ft_putendl.c \

OBJ		= $(SRC:.c=.o)

HEADERS = ./

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I$(HEADERS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
