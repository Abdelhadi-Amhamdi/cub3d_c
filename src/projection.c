/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:14:19 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/11 18:14:49 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

uint32_t	reverse_bytes(uint32_t num)
{
	return (((num >> 24) & 0xFF) | ((num >> 8) & 0xFF00) \
	| ((num << 8) & 0xFF0000) | ((num << 24) & 0xFF000000));
}

mlx_texture_t	*get_texture(t_ray ray, t_data *data)
{
	if (!ray.is_verthit)
	{
		if (ray.rayAngle > M_PI && ray.rayAngle < 2 * M_PI)
			return (data->img_data->north);
		else
			return (data->img_data->south);
	}
	else
	{
		if (ray.rayAngle > M_PI / 2 && ray.rayAngle < 1.5 * M_PI)
			return (data->img_data->west);
		else
			return (data->img_data->east);
	}
	return (NULL);
}

void	draw_strip(t_data *data, int id, int start, int end, float wall_height)
{
	t_txtr_data 	texture_data;
	mlx_texture_t	*txtr;
	uint32_t 		*pixels;
	
	txtr = get_texture(data->ray, data);
	pixels = (uint32_t *)txtr->pixels;
	texture_data.x_step = txtr->width / CUB_SIZE;
	texture_data.x_offset = ((int)((double)data->ray.x_hit * texture_data.x_step) % txtr->width);
	if(data->ray.is_verthit)
		texture_data.x_offset = ((int)((double)data->ray.y_hit * texture_data.x_step) % txtr->width);
	texture_data.y_step = (float)txtr->height / wall_height;
	texture_data.first_pixel = ((start - (data->window_height / 2) + (wall_height / 2)) * texture_data.y_step);
	while(start < end)
	{
		texture_data.y_offset = (int)texture_data.first_pixel;
		texture_data.color = pixels[texture_data.y_offset * txtr->height + texture_data.x_offset];
		texture_data.first_pixel+=texture_data.y_step;
		texture_data.color = reverse_bytes(texture_data.color);
		if (id >= 0 && id < data->window_width && start >= 0 && start < data->window_height)
			mlx_put_pixel(data->img, id, start , texture_data.color);
		start++;
	}
}

void	wall_projection(t_data *data, int id)
{
	float distance_pp;
	float wall_height;
	float real_dis;
	int start;
	int end;
	
	real_dis = data->ray.Distance * \
	cos(data->ray.rayAngle - data->p_data->player_Angle);
	distance_pp = (data->window_width / 2) / tan(data->fov / 2);
	wall_height = distance_pp * (CUB_SIZE / real_dis);
	start = (data->window_height / 2) - ((int)wall_height / 2);
	if (start < 0)
		start = 0;
	end = (data->window_height / 2) + ((int)wall_height / 2);
	if (end > data->window_height)
		end = data->window_height;
	draw_strip(data, id, start, end, wall_height);
}
