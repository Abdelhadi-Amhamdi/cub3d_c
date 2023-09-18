/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:26:37 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/18 13:25:48 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cast_horz_helper(t_data *data, t_line *line)
{
	line->yinter = floor(data->p_data->player_y / CUB_SIZE) * CUB_SIZE;
	if (data->ray.isdown)
		line->yinter += CUB_SIZE;
	line->xinter = data->p_data->player_x + \
	(line->yinter - data->p_data->player_y) / tan(data->ray.rayangle);
	line->delta_y = CUB_SIZE;
	if (data->ray.isup)
		line->delta_y *= -1;
	line->delta_x = CUB_SIZE / tan(data->ray.rayangle);
	if (data->ray.isleft && line->delta_x > 0)
		line->delta_x *= -1;
	else if (data->ray.isright && line->delta_x < 0)
		line->delta_x *= -1;
	line->next_x = line->xinter;
	line->next_y = line->yinter;
}

void	cast_horz(t_data *data, t_map_data *m_data, t_line *line)
{
	float	ycheck;

	cast_horz_helper(data, line);
	while (line->next_x >= 0 && line->next_y >= 0)
	{
		ycheck = line->next_y;
		if (data->ray.isup)
			ycheck -= 1;
		if (check_wall(data, m_data, line->next_x, ycheck))
		{
			line->h_hitx = line->next_x;
			line->h_hity = ycheck;
			line->h_dis = cal_distance(data->p_data->player_x, \
			data->p_data->player_y, line->next_x, line->next_y);
			return ;
		}
		else
		{
			line->next_x += line->delta_x;
			line->next_y += line->delta_y;
		}
	}
	line->h_dis = INT_MAX;
}

void	cast_vert_helper(t_data *data, t_line *line)
{
	line->xinter = floor(data->p_data->player_x / CUB_SIZE) * CUB_SIZE;
	if (data->ray.isright)
		line->xinter += CUB_SIZE;
	line->yinter = data->p_data->player_y + \
	(line->xinter - data->p_data->player_x) * tan(data->ray.rayangle);
	line->delta_x = CUB_SIZE;
	if (data->ray.isleft)
		line->delta_x *= -1;
	line->delta_y = CUB_SIZE * tan(data->ray.rayangle);
	if (data->ray.isup && line->delta_y > 0)
		line->delta_y *= -1;
	else if (data->ray.isdown && line->delta_y < 0)
		line->delta_y *= -1;
	line->next_x = line->xinter;
	line->next_y = line->yinter;
}

void	cast_vert(t_data *data, t_map_data *m_data, t_line *line)
{
	float	xcheck;

	cast_vert_helper(data, line);
	while (line->next_x >= 0 && line->next_y >= 0)
	{
		xcheck = line->next_x;
		if (data->ray.isleft)
			xcheck -= 1;
		if (check_wall(data, m_data, xcheck, line->next_y))
		{
			line->v_hitx = xcheck;
			line->v_hity = line->next_y;
			line->v_dis = cal_distance(data->p_data->player_x, \
			data->p_data->player_y, line->next_x, line->next_y);
			return ;
		}
		else
		{
			line->next_x += line->delta_x;
			line->next_y += line->delta_y;
		}
	}
	line->v_dis = INT_MAX;
}

void	raycasting(t_data *data, t_map_data *m_data)
{
	int		id;
	t_line	line;

	id = 0;
	data->ray.rayangle = data->p_data->player_angle - (data->fov / 2);
	while (id < data->num_rays)
	{
		line.v_dis = INT_MAX;
		line.h_dis = INT_MAX;
		data->ray.rayangle = normalize_angle(data->ray.rayangle);
		check_angle_dir(data, data->ray.rayangle, id);
		if (data->ray.rayangle != M_PI && data->ray.rayangle != \
		(M_PI * 2) && data->ray.rayangle != 0)
			cast_horz(data, m_data, &line);
		if (data->ray.rayangle != (M_PI * 0.5) && data->ray.rayangle != \
		(1.5 * M_PI))
			cast_vert(data, m_data, &line);
		init_ray_attr(data, &line);
		wall_projection(data, id);
		data->ray.rayangle += (data->fov / data->num_rays);
		id++;
	}
}
