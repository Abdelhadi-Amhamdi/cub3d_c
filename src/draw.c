/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:36:45 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/13 15:08:47 by aagouzou         ###   ########.fr       */
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

int	ft_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}

void	draw_line(t_data *data, int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	
	int	step;
	
	step = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy); 
	float xstep = dx / (float)step;
	float ystep = dy / (float)step;

	float x = x0;
	float y = y0;
	int i = 0;
	while(i < step)
	{
		if (x >= 0 && x < data->window_width && y >= 0 && y < data->window_height)
			mlx_put_pixel(data->img, x, y, 0xFFFFFFFF);
		x+=xstep;
		y+=ystep;
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
	mini_map_helper(data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
