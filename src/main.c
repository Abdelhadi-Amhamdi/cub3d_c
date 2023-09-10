/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:38:19 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/10 21:15:24 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	hook(void *param)
{
	t_data	*data;
	// int		new_mouse_x;
	// int		new_mouse_y;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP) \
	|| mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->p_data->walkDirc = 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) \
	|| mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->p_data->walkDirc = -1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->p_data->turnDirc = -1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->p_data->turnDirc = 1;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_1))
	// 	data->map_type = NONE_MAP;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	// 	data->player->move = 1;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	// 	data->player->move = -1;
	// else if (mlx_is_key_down(data->mlx, MLX_KEY_2))
	// 	data->map_type = NORMAL_MAP;
	// else if (mlx_is_key_down(data->mlx, MLX_KEY_3))
	// 	data->map_type = COSTUM_MAP;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		exit (0);
	// mlx_get_mouse_pos(data->mlx, &new_mouse_x, &new_mouse_y);
	// if (new_mouse_x >= 0 && new_mouse_x <= W_WIDTH && \
	// new_mouse_x != data->data->x_mouse && new_mouse_y \
	// >= 0 && new_mouse_y <= W_HEIGHT)
	// {
	// 	if (new_mouse_x < data->data->x_mouse)
	// 		data->player->turn = -1;
	// 	else
	// 		data->player->turn = 1;
	// 	data->data->x_mouse = new_mouse_x;
	// }
}

int	is_wall(int xinter, int yinter, t_map_data *data)
{
	int	new_x;
	int	new_y;

	new_x = (int)floor(xinter / CUB_SIZE);
	new_y = (int)floor(yinter / CUB_SIZE);
	if (new_x < 0 || new_x >= data->cols || new_y < 0 || new_y >= data->rows)
		return (1);
	return (data->map_body[new_y][new_x] == '1');
}

void	_update_data(t_data *data)
{
	float		new_y;
	float		new_x;
	float		steps;
	t_player_data	*player;

	player = data->p_data;
	player->player_Angle += (player->turnDirc * player->turnSpeed);
	player->player_Angle = normalize_angle(player->player_Angle);
	steps = player->walkDirc * (player->walkSpeed);
	new_x = player->player_x + (cos(player->player_Angle) * steps);
	new_y = player->player_y + (sin(player->player_Angle) * steps);
	if (!is_wall(new_x, new_y, data->map_data) && !is_wall(new_x, player->player_y, \
	data->map_data) && !is_wall(player->player_x, new_y, data->map_data))
	{
		player->player_x = floor(new_x);
		player->player_y = floor(new_y);
	}
	// _update_data_helper(game);
	// if (game->map_type == COSTUM_MAP)
	// 	calc_start_and_end(game);
	// _draw(game->data, game);
}

void	key_handler(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	hook(data);
	_update_data(data);
	data->p_data->walkDirc = 0;
	data->p_data->turnDirc = 0;
	_draw(data, data->map_data);
	// game->player->move = 0;
}


int	main(int argc, char *argv[])
{
	t_map_data		*map_data;
	t_data 			*data;
	t_player_data	*p_data;
	t_img_data		*img_data;

	if(argc != 2)
		return(0);
	map_data = parser(argc, argv);
	if (!map_data)
		return (0);
	p_data = init_player(map_data);
	img_data = init_images(map_data);
	data = init_data(map_data, p_data, img_data);
	_draw(data, map_data);
	mlx_loop_hook(data->mlx, key_handler, data);
	mlx_loop(data->mlx);
	return (0);
}