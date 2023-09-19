/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:41:47 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/19 16:08:59 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	get_responive_sizes(t_data *data, t_map_data *map_data)
{
	data->window_width = map_data->cols * CUB_SIZE;
	if (W_WIDTH < data->window_width)
		data->window_width = W_WIDTH;
	data->window_height = map_data->rows * CUB_SIZE;
	if (W_HEIGHT < data->window_height)
		data->window_height = W_HEIGHT;
}

float	player_angle(t_map_data *map_data)
{
	char	item;
	int		x;
	int		y;

	x = map_data->player_x;
	y = map_data->player_y;
	item = map_data->map_body[y][x];
	if (item == 'N')
		return (2 * M_PI);
	else if (item == 'S')
		return (M_PI);
	else if (item == 'W')
		return (1.5 * M_PI);
	else if (item == 'E')
		return (0.5 * M_PI);
	return (0);
}

t_player_data	*init_player(t_map_data *map_data)
{
	t_player_data	*player_data;

	player_data = malloc(sizeof(t_player_data));
	if (!player_data)
		return (NULL);
	player_data->player_x = (map_data->player_x * CUB_SIZE) + (CUB_SIZE / 2);
	player_data->player_y = (map_data->player_y * CUB_SIZE) + (CUB_SIZE / 2);
	player_data->turndirc = 0;
	player_data->walkdirc = 0;
	player_data->move_dirc = 0;
	player_data->more_speed = 0;
	player_data->player_angle = player_angle(map_data);
	player_data->turnspeed = 2 * (M_PI / 180);
	player_data->walkspeed = CUB_SIZE / 10;
	return (player_data);
}

// protect mlx_init && mlx_new_img
t_data	*init_data(t_map_data *map_data, \
t_player_data *p_data, t_img_data *m_data)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	get_responive_sizes(data, map_data);
	data->fov = 60 * (M_PI / 180);
	data->mlx = mlx_init(data->window_width, data->window_height, "cube", true);
	if (data->mlx == NULL)
	{
		print_error("mlx_init failed");
		ft_clean(data);
	}
	data->num_rays = data->window_width;
	data->img = NULL;
	data->p_data = p_data;
	data->img_data = m_data;
	data->map_data = map_data;
	data->map_type = COSUTM_MAP;
	mlx_get_mouse_pos(data->mlx, &data->mouse_x, &data->mouse_x);
	return (data);
}

t_img_data	*init_images(t_map_data *map_data)
{
	t_img_data	*img_data;

	img_data = malloc(sizeof(t_img_data));
	if (!img_data)
		return (NULL);
	img_data->south = mlx_load_png(map_data->south_img_path);
	img_data->west = mlx_load_png(map_data->west_img_path);
	img_data->north = mlx_load_png(map_data->north_img_path);
	img_data->east = mlx_load_png(map_data->east_img_path);
	if (!img_data->south || !img_data->west || \
	!img_data->east || !img_data->north)
	{
		if (img_data->south)
			mlx_delete_texture(img_data->south);
		if (img_data->north)
			mlx_delete_texture(img_data->north);
		if (img_data->west)
			mlx_delete_texture(img_data->west);
		if (img_data->east)
			mlx_delete_texture(img_data->east);
		return (free (img_data), NULL);
	}
	return (img_data);
}
