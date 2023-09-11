/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:36:45 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/11 18:14:37 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int ft_abs(int n) 
{
	return ((n > 0) ? n : (n * (-1)));
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
	int i = 0;
	int j = 0;
	while(i < data->window_height)
	{
		j = 0;
		while(j < data->window_width)
		{
			if(i < (data->window_height / 2))
				mlx_put_pixel(data->img, j, i, (data->map_data->ceil_rgb << 8) + 255);
			else
				mlx_put_pixel(data->img, j, i, (data->map_data->floor_rgb << 8) + 255);
			j++;
		}
		i++;
	}
}
