# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xalves <xavierfrpalves2@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/19 15:47:22 by msimoes           #+#    #+#              #
#    Updated: 2026/05/20 12:40:16 by xalves           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

SRC_FILES = get_next_line.c \
			get_next_line_utils.c

# $<  = pre-requesitos

# -c = n fazer link aos files compilados.
# Gerar .o em vez de executavel

# -o = output
O_FILES = $(SRC_FILES:.c=.o)

CC = cc
C_FLAGS = -Wall -Wextra -Werror

AR = ar rcs

all: $(NAME)

$(NAME): $(O_FILES)
	$(AR) $(NAME) $(O_FILES)

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all