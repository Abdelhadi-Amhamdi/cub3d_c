# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 11:34:11 by aagouzou          #+#    #+#              #
#    Updated: 2023/09/06 20:10:28 by aagouzou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CFLAGS = -Wall -Wextra -Werror
CC = CC -g

# FILES = main.c error.c init.c hook.c draw.c raycasting.c projection.c
FILES = src/main.c src/raycasting.c src/init.c src/error.c parse/parse_colors.c parse/parse_content.c parse/parse_main.c parse/utils.c \
	parse/utils1.c parse/utils2.c src/hook.c src/draw.c src/projection.c
OBJS = $(FILES:.c=.o)

SANI = -fsanitize=address

MLX42 = MLX42/build/libmlx42.a
I=-I/Users/aagouzou/.brew/Cellar/glfw/3.3.8/include/GLFW
L=-L/Users/aagouzou/.brew/Cellar/glfw/3.3.8/lib/
MLX = -framework Cocoa -framework OpenGL -framework IOKit -lglfw
LIBFT = libft/libft.a

all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SANI) $(OBJS) $(LIBFT) $(MLX42) $(I) $(L) $(MLX) -o $(NAME)

%.o: %.c cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# gcc main.c draw.c hook.c update.c  libft/libft.a MLX42/build/libmlx42.a -I/Users/aagouzou/.brew/Cellar/glfw/3.3.8/include/GLFW -L/Users/aagouzou/.brew/Cellar/glfw/3.3.8/lib/ -framework Cocoa -framework OpenGL -framework IOKit -lglfw -o lol