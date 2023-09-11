/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:41:47 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/11 15:31:17 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_responive_sizes(t_data *data, t_map_data *map_data)
{
	data->window_width = map_data->cols * CUB_SIZE;
	// if (W_WIDTH < data->window_width)
	// 	data->window_width = W_WIDTH;
	data->window_height = map_data->rows * CUB_SIZE;
	// if (W_HEIGHT < data->window_height)
	// 	data->window_height = W_HEIGHT;
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
		return(2 * M_PI);
	else if (item == 'S')
		return(M_PI);
	else if (item == 'W')
		return(1.5 * M_PI);
	else if (item == 'E')
		return(0.5 * M_PI);
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
	player_data->turnDirc = 0;
	player_data->walkDirc = 0;
	player_data->player_Angle = player_angle(map_data);
	player_data->turnSpeed = 2 * (M_PI / 180);
	player_data->walkSpeed = CUB_SIZE / 7;
	return (player_data);
}

// protect mlx_init && mlx_new_img
t_data	*init_data(t_map_data *map_data, \
t_player_data *p_data, t_img_data *m_data)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	get_responive_sizes(data, map_data);
	data->fov = 60 * (M_PI / 180);
	data->mlx = mlx_init(data->window_width, data->window_height, "cube", true);
	data->num_rays = data->window_width;
	data->img = NULL;
	data->p_data = p_data;
	data->img_data = m_data;
	data->map_data = map_data;
	return (data);
}

t_img_data	*init_images(t_map_data *map_data)
{
	t_img_data *img_data;

	img_data = malloc(sizeof(t_img_data));
	if (!img_data)
		return (NULL);
	img_data->south = mlx_load_png(map_data->south_img_path);
	img_data->west = mlx_load_png(map_data->south_img_path);
	img_data->north = mlx_load_png(map_data->south_img_path);
	img_data->east = mlx_load_png(map_data->south_img_path);
	return (img_data);
}

void	coloriez(t_data *data)
{
	int i = 0;
	int j = 0;
	while(i < data->window_height)
	{
		j = 0;
		while(j < data->window_width)
		{
			if(i < (data->window_height / 2))
				mlx_put_pixel(data->img, j, i, (data->map_data->ceil_rgb << 8) + 255);
			else
				mlx_put_pixel(data->img, j, i, (data->map_data->floor_rgb << 8) + 255);
			j++;
		}
		i++;
	}
}

void	_draw(t_data *data, t_map_data *m_data)
{
	if (data->img)
		mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->window_width, data->window_height);
	coloriez(data);
	raycasting(data, m_data);
	_draw_map(m_data, data);
	// draw_map(data, m_data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}

