/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:09:42 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/14 15:27:22 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	destroy_m_data(t_map_data *data)
{
	free(data->north_img_path);
	free(data->south_img_path);
	free(data->west_img_path);
	free(data->east_img_path);
	free(data->ceil_color);
	free(data->floor_color);
	ft_free(data->map_body);
	free(data);
}

void	destroy_imgs_data(t_img_data *data)
{
	mlx_delete_texture(data->east);
	mlx_delete_texture(data->west);
	mlx_delete_texture(data->north);
	mlx_delete_texture(data->south);
	free(data);
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
