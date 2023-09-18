/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:38:19 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/18 20:26:06 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_clean(void *d)
{
	t_data	*data;

	data = (t_data *)d;
	destroy_m_data(data->map_data);
	destroy_imgs_data(data->img_data);
	free (data->p_data);
	if (data->img)
		mlx_delete_image(data->mlx, data->img);
	free (data);
	exit (0);
}

// int	is_wall(int xinter, int yinter, t_map_data *data)
// {
// 	int	new_x;
// 	int	new_y;

// 	new_x = (int)ceil(xinter / CUB_SIZE);
// 	new_y = (int)ceil(yinter / CUB_SIZE);
// 	if (new_x < 0 || new_x >= data->cols || new_y < 0 || new_y >= data->rows)
// 		return (1);
// 	return (data->map_body[new_y][new_x] == '1');
// }

void	key_handler(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	hook(data);
	_update_data(data);
	data->p_data->walkdirc = 0;
	data->p_data->turndirc = 0;
	data->p_data->move_dirc = 0;
	data->p_data->more_speed = 0;
	_draw(data, data->map_data);
}

// void test()
// {
// 	system("leaks cub3d");
// }

int	main(int argc, char *argv[])
{
	t_map_data		*map_data;
	t_data			*data;
	t_player_data	*p_data;
	t_img_data		*img_data;

	if (argc != 2)
		return (0);
	map_data = parser(argc, argv);
	if (!map_data)
		return (0);
	p_data = init_player(map_data);
	if (!p_data)
		return (destroy_m_data(map_data), 0);
	img_data = init_images(map_data);
	if (!img_data)
		return (free(p_data), destroy_m_data(map_data), 0);
	data = init_data(map_data, p_data, img_data);
	if (!data)
		return (free(p_data), destroy_imgs_data(img_data), \
		destroy_m_data(map_data), 0);
	_draw(data, map_data);
	mlx_loop_hook(data->mlx, key_handler, data);
	mlx_loop(data->mlx);
	ft_clean(data);
	return (0);
}
