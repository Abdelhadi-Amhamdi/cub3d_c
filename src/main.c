/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:38:19 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/20 21:19:45 by aamhamdi         ###   ########.fr       */
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
	mlx_terminate(data->mlx);
	free (data);
	exit (0);
}

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

int	main(int argc, char *argv[])
{
	t_map_data		*map_data;
	t_data			*data;
	t_player_data	*p_data;
	t_img_data		*img_data;

	if (argc != 2)
		return (print_error(INVALID), 0);
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
	mlx_loop_hook(data->mlx, key_handler, data);
	mlx_close_hook(data->mlx, ft_clean, data);
	mlx_loop(data->mlx);
	ft_clean(data);
	return (0);
}
