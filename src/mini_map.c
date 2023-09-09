/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: original <original@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:49:46 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/09 16:04:20 by original         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	render_rect(t_rect rect, t_data *data)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height && \
	i >= 0 && i < W_HEIGHT)
	{
		j = rect.x;
		while (j < rect.x + rect.width && \
		j >= 0 && j < W_WIDTH)
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

// void	calc_start_and_end(t_game *game)
// {
// 	game->data->start_y = (game->player->y / ITEM_SIZE) - COSTUM_SIZE;
// 	if (game->data->start_y < 0)
// 		game->data->start_y = 0;
// 	game->data->end_y = (game->player->y / ITEM_SIZE) + COSTUM_SIZE;
// 	if (game->data->end_y > game->data->rows)
// 		game->data->end_y = game->data->rows;
// 	game->data->start_x = (game->player->x / ITEM_SIZE) - COSTUM_SIZE;
// 	if (game->data->start_x < 0)
// 		game->data->start_x = 0;
// 	game->data->end_x = (game->player->x / ITEM_SIZE) + COSTUM_SIZE;
// 	if (game->data->end_x > game->data->cols)
// 		game->data->end_x = game->data->cols;
// }

void	_draw_player(t_data *data)
{
	int		x;
	int		y;
	t_rect	rect;


	x = data->p_data->player_x * (float)MINI_MAP;
	y = data->p_data->player_y * (float)MINI_MAP;
	rect = init_rect(x, y, 4 * MINI_MAP, 'P');
	render_rect(rect, data);
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
	_draw_player(data);
}

// void	_draw_costum_map(t_data *data, t_game *game)
// {
// 	int		y;
// 	int		x;
// 	t_rect	rect;
// 	int		tmp;

// 	y = 0;
// 	tmp = data->start_x;
// 	while (data->start_y < data->end_y)
// 	{
// 		x = 0;
// 		game->data->start_x = tmp;
// 		while (data->start_x < data->end_x)
// 		{
// 			if (data->map->map_body[data->start_y][data->start_x] == '1')
// 			{
// 				rect = init_rect(x, y, ITEM_SIZE * (float)MINI_MAP, \
// 				data->map->map_body[data->start_y][data->start_x]);
// 				render_rect(rect, game);
// 			}
// 			game->data->start_x++;
// 			x++;
// 		}
// 		game->data->start_y++;
// 		y++;
// 	}
// }
