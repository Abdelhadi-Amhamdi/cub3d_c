/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:49:46 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/11 18:11:57 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	_draw_costum_map(t_data *data, t_mini_map map)
{
	int		y;
	int		x;
	t_rect	rect;
	int		tmp;

	y = 0;
	tmp = map.start_x;
	while (map.start_y < map.end_y)
	{
		x = 0;
		map.start_x = tmp;
		while (map.start_x < map.end_x)
		{
			if (data->map_data->map_body[map.start_y][map.start_x] == '1')
			{
				rect = init_rect(x, y, CUB_SIZE * (float)MINI_MAP, \
				data->map_data->map_body[map.start_y][map.start_x]);
				render_rect(rect, data);
			}
			map.start_x++;
			x++;
		}
		map.start_y++;
		y++;
	}
}

int	render_rect(t_rect rect, t_data *data)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height && \
	i >= 0 && i < data->window_height)
	{
		j = rect.x;
		while (j < rect.x + rect.width && \
		j >= 0 && j < data->window_width)
			mlx_put_pixel(data->img, j++, i, rect.color);
		++i;
	}
	return (0);
}

t_rect	init_rect(int x, int y, int size, char item)
{
	t_rect	rect;

	rect.x = x * size;
	rect.y = y * size;
	rect.width = size;
	rect.height = size;
	if (item == '0')
		rect.color = 0x000000FF;
	else if (item == '1')
		rect.color = 0xFFFFFFFF;
	if (item == 'P')
	{
		rect.color = 0xFFF3DAFF;
		rect.width = 4;
		rect.height = 4;
		rect.x = x;
		rect.y = y;
	}
	return (rect);
}

void	calc_start_and_end(t_mini_map *map, t_data *data)
{
	map->start_y = (data->p_data->player_y / CUB_SIZE) - COSTUM_SIZE;
	if (map->start_y < 0)
		map->start_y = 0;
	map->end_y = (data->p_data->player_y / CUB_SIZE) + COSTUM_SIZE;
	if (map->end_y > data->map_data->rows)
		map->end_y = data->map_data->rows;
	map->start_x = (data->p_data->player_x / CUB_SIZE) - COSTUM_SIZE;
	if (map->start_x < 0)
		map->start_x = 0;
	map->end_x = (data->p_data->player_x / CUB_SIZE) + COSTUM_SIZE;
	if (map->end_x > data->map_data->cols)
		map->end_x = data->map_data->cols;
}

void	mini_map_helper(t_data *data)
{
	t_mini_map mini_map;

	if (data->map_type == NORMAL_MAP)
		_draw_map(data->map_data, data);
	else if (data->map_type == COSUTM_MAP)
	{
		calc_start_and_end(&mini_map, data);
		_draw_costum_map(data, mini_map);
		_draw_player(data, &mini_map);
	}
}

void	_draw_player(t_data *data, t_mini_map *map)
{
	int		x;
	int		y;
	t_rect	rect;

	if (data->map_type == COSUTM_MAP)
	{
		x = (((data->p_data->player_x / CUB_SIZE) - map->start_x) * CUB_SIZE) * MINI_MAP;
		y = (((data->p_data->player_y / CUB_SIZE) - map->start_y) * CUB_SIZE) * MINI_MAP;
	}
	else
	{
		x = data->p_data->player_x * (float)MINI_MAP;
		y = data->p_data->player_y * (float)MINI_MAP;
	}
	rect = init_rect(x, y, 4 * MINI_MAP, 'P');
	render_rect(rect, data);
	draw_line(data, x + 2 , y + 2 , x + 2 + cos(data->p_data->player_Angle) \
	* 15, y + 2 + sin(data->p_data->player_Angle) * 15);
}

void	_draw_map(t_map_data *m_data, t_data *data)
{
	int		y;
	int		x;
	t_rect	rect;
	char	item;

	y = 0;
	while (y < m_data->rows)
	{
		x = 0;
		while (x < m_data->cols)
		{
			item = m_data->map_body[y][x];
			if (item == '1')
			{
				rect = init_rect(x, y, CUB_SIZE * MINI_MAP, item);
				render_rect(rect, data);
			}
			x++;
		}
		y++;
	}
	_draw_player(data, NULL);
}
