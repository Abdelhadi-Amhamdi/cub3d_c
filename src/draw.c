/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:36:45 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/18 21:57:21 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	render_rect(t_rect rect, t_data *data)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height && \
	i >= 0 && i < data->window_height)
	{
		j = rect.x;
		while (j < rect.x + rect.width && \
		j >= 0 && j < data->window_width)
			mlx_put_pixel(data->img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	draw_line(t_data *data, t_line *line)
{
	int		i;
	float	step;

	step = fabs(line->h_dis);
	if (fabs(line->h_dis) < fabs(line->v_dis))
		step = fabs(line->v_dis);
	i = 0;
	while (i < step)
	{
		if (line->next_x >= 0 && line->next_x < data->window_width && \
		line->next_y >= 0 && line->next_y < data->window_height)
			mlx_put_pixel(data->img, line->next_x, line->next_y, 0xFFFFFFFF);
		line->next_x += line->delta_x;
		line->next_y += line->delta_y;
		i++;
	}
}

void	coloriez(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->window_height)
	{
		j = 0;
		while (j < data->window_width)
		{
			if (i < (data->window_height / 2))
			{
				mlx_put_pixel(data->img, j, i, \
				(data->map_data->ceil_rgb << 8) + 255);
			}
			else
			{
				mlx_put_pixel(data->img, j, i, \
				(data->map_data->floor_rgb << 8) + 255);
			}
			j++;
		}
		i++;
	}
}

void	_draw(t_data *data, t_map_data *m_data)
{
	if (data->img)
		mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->window_width, \
	data->window_height);
	coloriez(data);
	raycasting(data, m_data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
