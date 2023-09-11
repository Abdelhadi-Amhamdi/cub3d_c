/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:26:37 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/11 16:10:03 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float	cast_horz(t_data *data, float angle, t_map_data *m_data, t_line *line)
{
	float	xcheck;
	float	ycheck;
	float	distance;

	line->yinter = floor(data->p_data->player_y / CUB_SIZE) * CUB_SIZE;
	if (data->ray.isdown)
		line->yinter += CUB_SIZE;
	line->xinter = data->p_data->player_x + \
	(line->yinter - data->p_data->player_y) / tan(angle);
	line->delta_y = CUB_SIZE;
	if (data->ray.isup)
		line->delta_y *= -1;
	line->delta_x = CUB_SIZE / tan(angle);
	if (data->ray.isleft && line->delta_x > 0)
		line->delta_x *= -1;
	else if (data->ray.isright && line->delta_x < 0)
		line->delta_x *= -1;
	line->horz_x = line->xinter;
	line->horz_y = line->yinter;
	while (line->horz_x >= 0 && line->horz_x <= data->window_width && \
	line->horz_y >= 0 && line->horz_y <= data->window_height)
	{
		xcheck = line->horz_x;
		ycheck = line->horz_y;
		if (data->ray.isup)
			ycheck -= 1;
		if (check_wall(data, m_data, xcheck, ycheck))
		{
			line->h_hitx = xcheck;
			line->h_hity = ycheck;
			break ;
		}
		else
		{
			line->horz_x += line->delta_x;
			line->horz_y += line->delta_y;
		}
	}
	distance = cal_distance(data->p_data->player_x, data->p_data->player_y, line->horz_x, line->horz_y);
	return (distance);
}

float	cast_vert(t_data *data, float angle, t_map_data *m_data, t_line *line)
{
	float	xcheck;
	float	ycheck;
	float	distance;

	line->xinter = floor(data->p_data->player_x / CUB_SIZE) * CUB_SIZE;
	if (data->ray.isright)
		line->xinter += CUB_SIZE;
	line->yinter = data->p_data->player_y + (line->xinter - data->p_data->player_x) * tan(angle);
	line->delta_x = CUB_SIZE;
	if (data->ray.isleft)
		line->delta_x *= -1;
	line->delta_y = CUB_SIZE * tan(angle);
	if (data->ray.isup && line->delta_y > 0)
		line->delta_y *= -1;
	else if (data->ray.isdown && line->delta_y < 0)
		line->delta_y *= -1;
	line->vert_x = line->xinter;
	line->vert_y = line->yinter;
	while (line->vert_x >= 0 && line->vert_x <= data->window_width && line->vert_y >= 0 && line->vert_y <= data->window_height)
	{
		xcheck = line->vert_x;
		if (data->ray.isleft)
			xcheck -= 1;
		ycheck = line->vert_y;
		if (check_wall(data, m_data, xcheck, ycheck))
		{
			line->v_hitx = xcheck;
			line->v_hity = ycheck;
			break ;
		}
		else
		{
			line->vert_x += line->delta_x;
			line->vert_y += line->delta_y;
		}
	}
	distance = cal_distance(data->p_data->player_x, data->p_data->player_y, line->vert_x, line->vert_y);
	return (distance);
}

void	raycasting(t_data *data, t_map_data *m_data)
{
	int		id;
	t_line	line;
	float	vert_dis;
	float	horz_dis;
	float	rayangle;

	rayangle = data->p_data->player_Angle - (data->fov / 2);
	id = 0;
	while (id < data->num_rays)
	{
		rayangle = normalize_angle(rayangle);
		data->ray.rayAngle = rayangle;
		check_angle_dir(data, rayangle, id);
		horz_dis = cast_horz(data, rayangle, m_data, &line);
		vert_dis = cast_vert(data, rayangle, m_data, &line);
		if (vert_dis < horz_dis)
		{
			data->ray.Distance = vert_dis;
			data->ray.is_verthit = 1;
			data->ray.x_hit = line.v_hitx;
			data->ray.y_hit = line.v_hity;
		}
		else
		{
			data->ray.Distance = horz_dis;
			data->ray.x_hit = line.h_hitx;
			data->ray.y_hit = line.h_hity;
		}
		rayangle += (data->fov / data->num_rays);
		id++;
		wall_projection(data, id);
	}
}
