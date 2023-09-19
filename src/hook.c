/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:57:21 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/19 10:00:16 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) \
	|| mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->p_data->walkdirc = 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) \
	|| mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->p_data->walkdirc = -1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->p_data->turndirc = -1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->p_data->turndirc = 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->p_data->move_dirc = 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->p_data->move_dirc = -1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
		data->p_data->more_speed = 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		ft_clean(data);
}

int	check_new_positions(float x, float y, t_data *data)
{
	int				distance;
	t_player_data	*player;

	player = data->p_data;
	distance = CUB_SIZE / 7;
	if (!is_wall(x, y, data->map_data) && !is_wall(x, player->player_y, \
	data->map_data) && !is_wall(player->player_x, y, data->map_data) \
	&& !is_wall(x + distance, y + distance, data->map_data) && \
	!is_wall(x - distance, y - distance, data->map_data))
		return (1);
	return (0);
}

void	_update_data_helper(t_data *data)
{
	t_player_data	*player;
	double			new_angle;
	float			steps;
	float			x;
	float			y;

	player = data->p_data;
	if (player->move_dirc)
	{
		new_angle = player->player_angle + (90 * (M_PI / 180) \
		* player->move_dirc);
		new_angle = normalize_angle(new_angle);
		steps = 1 * (player->walkspeed);
		x = player->player_x + (cos(new_angle) * steps);
		y = player->player_y + (sin(new_angle) * steps);
		if (check_new_positions(x, y, data))
		{
			player->player_x = round(x);
			player->player_y = round(y);
		}
	}
}

void	_update_data(t_data *data)
{
	float			y;
	float			x;
	float			steps;
	t_player_data	*player;

	player = data->p_data;
	if (player->turndirc)
	{
		player->player_angle += (player->turndirc * player->turnspeed);
		player->player_angle = normalize_angle(player->player_angle);
	}
	if (player->walkdirc)
	{
		steps = player->walkdirc * player->walkspeed;
		if (player->more_speed)
			steps *= 2;
		x = player->player_x + (cos(player->player_angle) * steps);
		y = player->player_y + (sin(player->player_angle) * steps);
		if (check_new_positions(x, y, data))
		{
			player->player_x = round(x);
			player->player_y = round(y);
		}
	}
	_update_data_helper(data);
}
