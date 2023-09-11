/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:14:19 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/11 16:46:22 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

uint32_t	reverse_bytes(uint32_t num)
{
	return (((num >> 24) & 0xFF) | ((num >> 8) & 0xFF00) \
	| ((num << 8) & 0xFF0000) | ((num << 24) & 0xFF000000));
}

uint32_t	*get_texture(t_ray ray, t_data *data)
{
	if (!ray.is_verthit)
	{
		if (ray.rayAngle > M_PI && ray.rayAngle < 2 * M_PI)
			return ((uint32_t *)data->img_data->north->pixels);
		else
			return ((uint32_t *)data->img_data->south->pixels);
	}
	else
	{
		if (ray.rayAngle > M_PI / 2 && ray.rayAngle < 1.5 * M_PI)
			return ((uint32_t *)data->img_data->west->pixels);
		else
			return ((uint32_t *)data->img_data->east->pixels);
	}
	return (NULL);
}

void	draw_strip(t_data *data, int id, int start, int end, float wall_height)
{
	uint32_t color=0;
	int xoffset;
	int yoffset;
	double x_step;
	double s;
	
	uint32_t *txtr = get_texture(data->ray, data);
	x_step = data->img_data->east->width / CUB_SIZE;
	xoffset = ((int)((double)data->ray.x_hit * x_step) % data->img_data->east->width);
	if(data->ray.is_verthit)
		xoffset = ((int)((double)data->ray.y_hit * x_step) % data->img_data->east->width);
	float texture_scale = (float)data->img_data->east->height / wall_height;
	s = ((start - data->window_height / 2 + wall_height / 2) * texture_scale);
	while(start < end)
	{
		yoffset = (int)s;
		color = txtr[yoffset * data->img_data->east->height + xoffset];
		s+=texture_scale;
		color = reverse_bytes(color);
		mlx_put_pixel(data->img, id, start , color);
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
