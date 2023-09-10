/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:36:45 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/09 21:05:19 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int ft_abs(int n) 
{
	return ((n > 0) ? n : (n * (-1)));
}

void    draw_line(t_data    *data, int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	
	int   step = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy); 
	
	float xstep = dx / (float)step;
	float ystep = dy / (float)step;

	float x = x0;
	float y = y0;
	int i = 0;
	while(i < step)
	{
		mlx_put_pixel(data->img, x, y, 0xFF0000FF);
		x+=xstep;
		y+=ystep;
		i++;
	}
}

void    draw_grid(t_data *data, int x, int y, int color)
{
    int i;
    int j;

    i = 0;
    while(i < (CUB_SIZE ))
    {
        j = 0;
        while(j < (CUB_SIZE ))
        {
            mlx_put_pixel(data->img, (x + i), (y + j) , color );
            if (j == 0 || i == 0 || j == CUB_SIZE - 1 || i == CUB_SIZE - 1)
                mlx_put_pixel(data->img, (x + i), (y + j), 0x0047910F);
            j++;
        }
        i++;
    }
}

void    draw_map(t_data *data ,t_map_data *m_data)
{
    int i= 0, j = 0;
    while(m_data->map_body[i])
    {
        j = 0;
        while(m_data->map_body[i][j])
        {
            if(m_data->map_body[i][j] == '1')   
                draw_grid(data, (j * CUB_SIZE), (i * CUB_SIZE), 0xFFFFFFFF);
            else
                draw_grid(data, (j * CUB_SIZE), (i * CUB_SIZE), 0x000000FF );
                
            j++;
        }
        i++;
    }
}

// void    draw_plyr(t_map_data *data)
// {
//     int x;
//     int y;

//     x = 0;
//     y = 0;
//     while(y < 10)
//     {
//         x = 0;
//         while(x < 10)
//         {
//             mlx_put_pixel(data->img,(data->player_x + x),(data->player_y + y) ,  0xff2424FF);
//             x++;
//         }
//         y++;
//     }
// }