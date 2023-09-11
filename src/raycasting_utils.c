/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:36:41 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/11 13:24:57 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, (M_PI * 2));
	if (angle < 0)
		angle = (M_PI * 2) + angle;
	return (angle);
}

int	check_wall(t_data *data, t_map_data *m_data, float x, float y)
{
	int	check_x;
	int	check_y;

	if (x <= 0 || x >= data->window_width || y <= 0 || y >= data->window_height)
		return (1);
	check_x = (int)(floor(x / CUB_SIZE));
	check_y = (int)(floor(y / CUB_SIZE));
	return (m_data->map_body[check_y][check_x] == '1');
}

float	cal_distance(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	check_angle_dir(t_data *data, float angle, int id)
{
	(void)id;
	data->ray.isdown = 0;
	data->ray.isleft = 0;
	data->ray.isright = 0;
	data->ray.isup = 0;
	if (angle > M_PI)
		data->ray.isup = 1;
	data->ray.isdown = !data->ray.isup;
	if (angle > (M_PI / 2) && angle < ((3 * M_PI) / 2))
		data->ray.isleft = 1;
	data->ray.isright = !data->ray.isleft;
	data->ray.is_verthit = 0;
}
