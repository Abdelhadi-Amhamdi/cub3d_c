/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:59:08 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/20 22:34:41 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "../../libs/libft/libft.h"
# include "cub3d_bonus.h"
# include <stdlib.h>
# include <stdio.h>

# define WALL 49
# define N_PLAYER 78
# define S_PLAYER 83
# define W_PLAYER 87
# define E_PLAYER 69
# define WH_SAPCE 32
# define EMPTY 48

# define EMPTY_LINE -1
# define DATA_ITEM 1
# define INVALID_CHAR 2

# define NPLAYER "No Player, Or More Than One Found !"
# define NITEM "Invalid Item On The Map !"
# define NWALLS "The Map Not Sourended By Walls !"
# define NEXTENSION "Map Filename Extension Not Valid !"
# define NIMG "images missing or not valid !"
# define NCOLOR "Rgb Color Missing Or Not Valid !"
# define NDATA "Game Data Missing Or Not Completed !"
# define NMAP "Empty file !"
# define ELINE "Empty Line In Map !"
# define DDATA "Duplicate data in map !"

typedef struct s_map_data
{
	char				*north_img_path;
	char				*south_img_path;
	char				*west_img_path;
	char				*east_img_path;
	char				*floor_color;
	char				*ceil_color;
	unsigned int		floor_rgb;
	unsigned int		ceil_rgb;
	char				**map_body;
	int					rows;
	int					cols;
	int					player_x;
	int					player_y;
}	t_map_data;

t_map_data	*parser(int args_count, char **args_values);
int			parse_map_content(t_map_data *map_data);
int			costumaize_map_data(t_map_data *map_data, char **map);
int			get_palyer_position(t_map_data *map);

int			check_player(t_map_data *data);

int			check_map_extension(char *filename);
void		ft_free(char **tabs);
void		init_data_map(t_map_data *data);
char		**read_map_file(char *file_name);
int			ft_tabs_len(char **map);
char		**ft_tabs_dup(char **map);
void		destroy_map_data(t_map_data *data);

void		calc_color(unsigned int *rgb, int r, int g, int b);
int			check_value(int value);
int			ft_check(char *color);
int			parse_color(char **color, int *red, int *green, int *blue);
int			parse_colors_values(t_map_data *map_data);

int			ft_is_space(char c);
int			check_each_item(char item);
char		**create_new_map(int rows, int cols, char **map);
int			check_empty(int y, int x, t_map_data *map);
int			check_if_enclosed_by_walls(t_map_data *map_data);
int			check_items(char **map);
void		get_rows_and_cols(char **map, int *rows, int *cols);
int			fill_map(t_map_data *map_data);
int			parse_map_data(t_map_data *map_data);

int			parse_images_paths(t_map_data *map_data);

char		**read_map_file(char *file_name);
int			parse_map_data(t_map_data *map_data);

void		print_error(char *error);
int			is_data(char *str);
int			is_valid_char(char c);

int			is_valid_data(char *str, char *cmp, size_t len);

#endif