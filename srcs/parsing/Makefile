NAME = parsing.a

SRC_FILES = check_map.c \
			cleanup.c \
			init_map.c \
			init_textures.c \
			normalize_map.c \
			parsing.c

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
