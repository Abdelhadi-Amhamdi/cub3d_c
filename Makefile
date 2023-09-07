# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 04:28:13 by aamhamdi          #+#    #+#              #
#    Updated: 2023/09/06 21:04:49 by aamhamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---- global vars ----- #

NAME		= cub3d
CC			= cc -g -Wall -Wextra -Werror -o3 -ffast-math #-fsanitize=address
MLX			= -framework Cocoa -framework OpenGL -framework IOKit -lglfw

# ---- libs ---------- #

MLX42		= /Users/${USER}/MLX42/build/libmlx42.a
LIBFT		= $(LIBFT_PATH)/libft.a

# ----- PATH && includes ---- #

INC			= includes/
RAY_CAST	= src/
PARSE		= parse/
PARSE		= parse/
LIBFT_PATH	= libft
I			= -I/Users/${USER}/.brew/Cellar/glfw/3.3.8/include/GLFW
L			= -L/Users/${USER}/.brew/Cellar/glfw/3.3.8/lib

BUILD_DIR	= build/

# ---- files ------ #

src			= main.c error.c init.c hook.c raycasting.c projection.c mini_map.c
srcs		= $(addprefix $(RAY_CAST), $(src))

p_src		= parse_main.c utils.c utils1.c parse_colors.c parse_content.c utils2.c
p_srcs		= $(addprefix $(PARSE), $(p_src))

obj 		= $(src:.c=.o) $(p_src:.c=.o)
objs 		= $(addprefix $(BUILD_DIR), $(obj))


# ---- RULES ---- #

$(BUILD_DIR)%.o: %.c
	$(CC) $< -c -o $@ $(I)

all : $(LIBFT) $(BUILD_DIR) $(NAME)

$(BUILD_DIR)%.o: $(RAY_CAST)%.c
	$(CC) $< -c -o $@
	
$(BUILD_DIR)%.o: $(PARSE)%.c
	$(CC) $< -c -o $@

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(NAME) : $(objs)
	$(CC) $(objs) $(MLX42) $(LIBFT) -o $@ $(I) $(L) $(MLX)

$(LIBFT):
	make -s -C $(LIBFT_PATH)

clean :
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -s -C $(LIBFT_PATH)

re:	fclean all