/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:57:21 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/19 15:00:28 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	mouse_hook_helper(t_data *data)
{
	int		new_mouse_x;
	int		new_mouse_y;

	mlx_get_mouse_pos(data->mlx, &new_mouse_x, &new_mouse_y);
	if (new_mouse_x >= 0 && new_mouse_x <= data->window_width && \
	new_mouse_x != data->mouse_x && new_mouse_y \
	>= 0 && new_mouse_y <= data->window_height)
	{
		if (new_mouse_x < data->mouse_x)
			data->p_data->player_angle -= \
			get_angle_offset(data->mouse_x, new_mouse_x, data->window_width);
		else
			data->p_data->player_angle += \
			get_angle_offset(new_mouse_x, data->mouse_x, data->window_width);
		data->mouse_x = new_mouse_x;
	}
	if (new_mouse_x >= data->window_width || new_mouse_x <= 0)
		data->mouse_x = data->window_width / 2;
}

void	map_hook_helper(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_1))
		data->map_type = NONE_MAP;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_2))
		data->map_type = NORMAL_MAP;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_3))
		data->map_type = COSUTM_MAP;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		ft_clean(data);
}

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
	map_hook_helper(data);
	mouse_hook_helper(data);
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
