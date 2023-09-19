# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 04:28:13 by aamhamdi          #+#    #+#              #
#    Updated: 2023/09/19 10:41:44 by aamhamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---- global vars ----- #

NAME		= cub3d
NAME_BONUS	= cub3d_bonus
CC			= cc -g -Wall -Wextra -Werror -o3 -ffast-math #-fsanitize=address
MLX			= -framework Cocoa -framework OpenGL -framework IOKit -lglfw

# ---- libs ---------- #

MLX42		= /Users/${USER}/MLX42/build/libmlx42.a
LIBFT		= $(LIBFT_PATH)/libft.a

# ----- PATH && includes ---- #

INC			= include/
RAY_CAST	= src/
PARSE		= parse/
PARSE		= parse/
BONUS		= bonus/
LIBFT_PATH	= libs/libft
# I			= -I/usr/local/Cellar/glfw/3.3.8/include/GLFW
# L			= -L/usr/local/Cellar/glfw/3.3.8/lib
I			= -I/Users/${USER}/.brew/Cellar/glfw/3.3.8/include/GLFW
L			= -L/Users/${USER}/.brew/Cellar/glfw/3.3.8/lib

BUILD_DIR	= build/

# ---- files ------ #

src			= main.c init.c raycasting.c draw.c raycasting_utils.c projection.c hook.c clean.c
srcs		= $(addprefix $(RAY_CAST), $(src))

p_src		= parse_main.c utils.c utils1.c parse_colors.c parse_content.c utils2.c parse_utils.c color_utils.c 
p_srcs		= $(addprefix $(PARSE), $(p_src))

b_files		= main_bonus.c init_bonus.c raycasting_bonus.c draw_bonus.c raycasting_utils_bonus.c projection_bonus.c hook_bonus.c clean_bonus.c
b_src		= $(addprefix $(RAY_CAST), $(b_files))
b_srcs		= $(addprefix $(BONUS), b_src)

b_p_files		= parse_main_bonus.c utils_bonus.c utils1_bonus.c parse_colors_bonus.c parse_content_bonus.c utils2_bonus.c parse_utils_bonus.c color_utils_bonus.c 
b_p_src		= $(addprefix $(PARSE), $(b_p_files))
b_p_srcs		= $(addprefix $(BONUS), b_p_src)


obj 		= $(src:.c=.o) $(p_src:.c=.o)
objs 		= $(addprefix $(BUILD_DIR), $(obj))

p_obj		= $(b_files:.c=.o) $(b_p_files:.c=.o)
p_objs		= $(addprefix $(BUILD_DIR), $(p_obj))

# ---- RULES ---- #

$(BUILD_DIR)%.o: %.c
	$(CC) $< -c -o $@ $(I)

all : $(LIBFT) $(BUILD_DIR) $(NAME)

$(BUILD_DIR)%.o: $(RAY_CAST)%.c
	$(CC) $< -c -o $@
	
$(BUILD_DIR)%.o: $(PARSE)%.c
	$(CC) $< -c -o $@
	
$(BUILD_DIR)%.o: $(BONUS)$(RAY_CAST)%.c
	$(CC) $< -c -o $@
	
$(BUILD_DIR)%.o: $(BONUS)$(PARSE)%.c
	$(CC) $< -c -o $@

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(NAME) : $(objs)
	$(CC) $(objs) $(MLX42) $(LIBFT) -o $@ $(I) $(L) $(MLX)
	
$(NAME_BONUS) : $(b_objs)
	$(CC) $(b_objs) $(MLX42) $(LIBFT) -o $@ $(I) $(L) $(MLX)

$(LIBFT):
	make -s -C $(LIBFT_PATH)

bonus : $(NAME_BONUS)

clean :
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	make fclean -s -C $(LIBFT_PATH)

re:	fclean all