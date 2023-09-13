/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:46:24 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/13 23:13:32 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	is_player(int x, int y, t_map_data *map)
{
	return (map->map_body[y][x] == N_PLAYER \
	|| map->map_body[y][x] == S_PLAYER \
	|| map->map_body[y][x] == E_PLAYER \
	|| map->map_body[y][x] == W_PLAYER);
}

int	fill_map(t_map_data *map_data)
{
	char	**new_map;

	get_rows_and_cols(map_data->map_body, &map_data->rows, &map_data->cols);
	new_map = create_new_map(map_data->rows, \
	map_data->cols, map_data->map_body);
	ft_free(map_data->map_body);
	map_data->map_body = new_map;
	return (0);
}

void	costumaize_map_data(t_map_data *map_data, char **map)
{
	int	i;

	i = 0;
	init_data_map(map_data);
	while (map[i])
	{
		if (!ft_strncmp(map[i], "NO ", 3))
			map_data->north_img_path = ft_strtrim((map[i] + 3), " ");
		else if (!ft_strncmp(map[i], "SO ", 3))
			map_data->south_img_path = ft_strtrim((map[i] + 3), " ");
		else if (!ft_strncmp(map[i], "WE ", 3))
			map_data->west_img_path = ft_strtrim((map[i] + 3), " ");
		else if (!ft_strncmp(map[i], "EA ", 3))
			map_data->east_img_path = ft_strtrim((map[i] + 3), " ");
		else if (!ft_strncmp(map[i], "F ", 2))
			map_data->floor_color = ft_strdup(map[i] + 2);
		else if (!ft_strncmp(map[i], "C ", 2))
			map_data->ceil_color = ft_strdup(map[i] + 2);
		else
			break ;
		i++;
	}
	map_data->map_body = ft_tabs_dup(map + i);
	ft_free(map);
}

int	parse_map_data(t_map_data *map_data)
{
	if (parse_images_paths(map_data))
		return (print_error(NIMG), 1);
	if (parse_colors_values(map_data))
		return (print_error(NCOLOR), 1);
	if (parse_map_content(map_data))
		return (1);
	return (0);
}

int	get_palyer_position(t_map_data *map)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = -1;
	while (map->map_body[y])
	{
		x = 0;
		while (map->map_body[y][x])
		{
			if (is_player(x, y, map))
			{
				map->player_x = x;
				map->player_y = y;
				count++;
			}
			x++;
		}
		y++;
	}
	return (count);
}
