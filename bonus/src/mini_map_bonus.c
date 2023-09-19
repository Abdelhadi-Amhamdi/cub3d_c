/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:49:46 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/19 10:47:57 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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

void	init_line(t_line *line, t_data *data, int x, int y)
{
	float	step;

	line->h_dis = (x + 2 + cos(data->p_data->player_angle) * 15) - (x + 2);
	line->v_dis = (y + 2 + sin(data->p_data->player_angle) * 15) - (y + 2);
	step = fabs(line->h_dis);
	if (fabs(line->h_dis) < fabs(line->v_dis))
		step = fabs(line->v_dis);
	line->delta_x = line->h_dis / step;
	line->delta_y = line->v_dis / step;
	line->next_x = (x + 2);
	line->next_y = (y + 2);
}

void	_draw_player(t_data *data, t_mini_map *map)
{
	int		x;
	int		y;
	t_line	line;
	t_rect	rect;

	if (data->map_type == COSUTM_MAP)
	{
		x = (((data->p_data->player_x / CUB_SIZE) - map->start_x) \
		* CUB_SIZE) * MINI_MAP;
		y = (((data->p_data->player_y / CUB_SIZE) - map->start_y) \
		* CUB_SIZE) * MINI_MAP;
	}
	else
	{
		x = ((data->p_data->player_x / CUB_SIZE) * CUB_SIZE) * MINI_MAP;
		y = ((data->p_data->player_y / CUB_SIZE) * CUB_SIZE) * MINI_MAP;
	}
	x -= 4;
	y -= 4;
	rect = init_rect(x, y, 4 * MINI_MAP, 'P');
	render_rect(rect, data);
	init_line(&line, data, x, y);
	draw_line(data, &line);
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
