/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:39:49 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/06 18:15:39 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**create_new_map(int rows, int cols, char **map)
{
	int		y;
	int		x;
	char	**new_map;

	y = -1;
	new_map = malloc(sizeof(char *) * (rows + 1));
	if (!new_map)
		return (NULL);
	while (++y < rows)
	{
		x = 0;
		new_map[y] = malloc(sizeof(char) * (cols + 1));
		if (!new_map[y])
			return (ft_free(new_map), NULL);
		while (x < cols && map[y][x])
		{
			new_map[y][x] = map[y][x];
			x++;
		}
		while (x < cols)
			new_map[y][x++] = ' ';
		new_map[y][x] = '\0';
	}
	new_map[y] = NULL;
	return (new_map);
}

int	check_empty(int y, int x, t_map_data *map)
{
	if ((y - 1) < 0 || (y + 1) > (map->rows - 1) \
	|| (x - 1) < 0 || (x + 1) > (map->cols - 1))
		return (1);
	if (map->map_body[y][x - 1] == WH_SAPCE \
	|| map->map_body[y][x + 1] == WH_SAPCE)
		return (1);
	if (map->map_body[y - 1][x] == WH_SAPCE \
	|| map->map_body[y + 1][x] == WH_SAPCE)
		return (1);
	return (0);
}

int	check_if_enclosed_by_walls(t_map_data *map_data)
{
	int	y;
	int	x;

	y = 0;
	while (map_data->map_body[y])
	{
		x = 0;
		while (map_data->map_body[y][x])
		{
			if (map_data->map_body[y][x] == EMPTY)
			{
				if (check_empty(y, x, map_data))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_items(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (check_each_item(map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	get_rows_and_cols(char **map, int *rows, int *cols)
{
	int	rows_length;
	int	cols_size;
	int	size;

	rows_length = 0;
	cols_size = 0;
	while (map[rows_length])
	{
		size = ft_strlen(map[rows_length]);
		if (size > cols_size)
			cols_size = size;
		rows_length++;
	}
	*cols = cols_size;
	*rows = rows_length;
}
