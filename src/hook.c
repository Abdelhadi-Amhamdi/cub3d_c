/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:15:57 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/06 20:14:54 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// int check_wall(t_map_data *data, float x, float y)
// {
//     int check_x;
//     int check_y;

//     if(x <= 0 || x >= data->win_width || y <= 0 || y >= data->win_height)
//         return (1);
//     check_x = (int)(floor(x / CUB_SIZE));
//     check_y = (int)(floor(y / CUB_SIZE));
//     return (data->map_body[check_y][check_x] == '1');
// }

void    update_plyr(t_map_data *data)
{
    float step;
    float new_x;
    float new_y;

    data->roatAngle += data->turnDirc * data->turnSpeed;

    
    // printf("roating angle: %f\n",data->roatAngle);
    // printf("turn dirc: %f\n",data->turnDirc);
    step = data->walkDirc * data->walkSpeed;

    new_x = (data->player_x + cos(data->roatAngle) * step);
    new_y = (data->player_y + sin(data->roatAngle) * step);
    if(!check_wall(data, new_x, new_y))
    {
        data->player_x = new_x;
        data->player_y = new_y;
    }
    
}

int ft_abs(int n) { return ((n > 0) ? n : (n * (-1))); }

void    draw_line(t_map_data    *data, int x0, int y0, int x1, int y1)
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

void    coloriez(t_map_data *data)
{
    int i = 0;
    int j = 0;
    while(i < data->win_height)            
    {
        j = 0;
        while(j < data->win_width)
        {
            if(i < (data->win_height / 2))
                mlx_put_pixel(data->img, j, i, 0xfcba03FF);
            else
                mlx_put_pixel(data->img, j, i, 0x66ebffFF);
            j++;
        }
        i++;
    }
}

void    hook_handler(void   *param)
{
    t_map_data *data;
    
    data = (t_map_data *)param;
    mlx_delete_image(data->mlx, data->img);
    data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
    if(!data->img || mlx_image_to_window(data->mlx,data->img, 0,0))
        ft_error("error: mlx new image failed");
    coloriez(data);
    update_plyr(data);
    // draw_map(data);
    raycasting(data);
//     draw_plyr(data);
//     draw_line(data,(data->player_x), (data->player_y), (data->player_x + cos(data->roatAngle) * 50), (data->player_y + sin(data->roatAngle) * 50));
    wall_projection(data);
}

void    key_handler(mlx_key_data_t keycode, void    *param)
{
    t_map_data  *data;
    data = (t_map_data  *)param;
    if ((keycode.key == MLX_KEY_UP || keycode.key == MLX_KEY_W) && keycode.action == MLX_PRESS)
        data->walkDirc = 1;
	if ((keycode.key == MLX_KEY_DOWN || keycode.key == MLX_KEY_S) && keycode.action == MLX_PRESS)
        data->walkDirc = -1;
	if ((keycode.key == MLX_KEY_RIGHT || keycode.key == MLX_KEY_D) && keycode.action == MLX_PRESS)
        data->turnDirc = 1;
	if ((keycode.key == MLX_KEY_LEFT || keycode.key == MLX_KEY_A) && keycode.action == MLX_PRESS)
        data->turnDirc = -1;

    if ((keycode.key == MLX_KEY_UP || keycode.key == MLX_KEY_W) && keycode.action == MLX_RELEASE)
        data->walkDirc = 0;
    if ((keycode.key == MLX_KEY_DOWN || keycode.key == MLX_KEY_S) && keycode.action == MLX_RELEASE)
        data->walkDirc = 0;
	if ((keycode.key == MLX_KEY_RIGHT || keycode.key == MLX_KEY_D) && keycode.action == MLX_RELEASE)
        data->turnDirc = 0;
	if ((keycode.key == MLX_KEY_LEFT || keycode.key == MLX_KEY_A) && keycode.action == MLX_RELEASE)
        data->turnDirc = 0;
}