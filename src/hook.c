/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:10:19 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/10 20:59:58 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void    update_plyr(t_map_data *data)
// {
// 	float step;
// 	float new_x;
// 	float new_y;

// 	data->roatAngle += data->turnDirc * data->turnSpeed;
// 	data->roatAngle = normalize_angle(data->roatAngle);
// 	step = data->walkDirc * data->walkSpeed;
// 	new_x = data->player_x + cos(data->roatAngle) * step;
// 	new_y = data->player_y + sin(data->roatAngle) * step;
// 	if(!check_wall(data, new_x, new_y))
// 	{
// 		data->player_x = new_x;
// 		data->player_y = new_y;
// 	}
// }

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

void	coloriez(t_data *data)
{
	int i = 0;
	int j = 0;
	while(i < data->window_height)
	{
		j = 0;
		while(j < data->win_width)
		{
			if(i < (data->window_height / 2))
				mlx_put_pixel(data->img, j, i, 0x66ebffFF);
			else
				mlx_put_pixel(data->img, j, i, data->floor_rgb);
			j++;
		}
		i++;
	}
}

void	_draw(t_data *data)
{
	if (data->img)
		mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->window_width, data->window_height);
	coloriez(data);
	// raycasting(data);
	// if (game->map_type == NORMAL_MAP)
	// {
	// 	_draw_map(data, game);
	// 	_draw_player(game, game->player, game->data, NORMAL_MAP);
	// }
	// else if (game->map_type == COSTUM_MAP)
	// {
	// 	_draw_player(game, game->player, game->data, COSTUM_MAP);
	// 	_draw_costum_map(data, game);
	// }
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

// void	hook_handler(void	*param)
// {
// 	t_data *data;
	
// 	data = (t_data *)param;
// 	if (data->img)
// 		mlx_delete_image(data->mlx, data->img);
// 	data->img = mlx_new_image(data->mlx, data->window_width, data->window_height);
// 	if(!data->img || mlx_image_to_window(data->mlx,data->img, 0,0))
// 		ft_error("error: mlx new image failed");
// 	// coloriez(data);
// 	update_plyr(data);
// 	raycasting(data);
// 	wall_projection(data);
// 	_draw_map(data);
// }

// void    key_handler(mlx_key_data_t keycode, void    *param)
// {
// 	t_map_data  *data;
// 	data = (t_map_data  *)param;
// 	if ((keycode.key == MLX_KEY_UP || keycode.key == MLX_KEY_W) && keycode.action == MLX_PRESS)
// 		data->walkDirc = 1;
// 	if ((keycode.key == MLX_KEY_DOWN || keycode.key == MLX_KEY_S) && keycode.action == MLX_PRESS)
// 		data->walkDirc = -1;
// 	if ((keycode.key == MLX_KEY_RIGHT) && keycode.action == MLX_PRESS)
// 		data->turnDirc = 1;
// 	if ((keycode.key == MLX_KEY_LEFT) && keycode.action == MLX_PRESS)
// 		data->turnDirc = -1;
// 	if ((keycode.key == MLX_KEY_ESCAPE) && keycode.action == MLX_PRESS)
// 		exit (0);

// 	if ((keycode.key == MLX_KEY_UP || keycode.key == MLX_KEY_W) && keycode.action == MLX_RELEASE)
// 		data->walkDirc = 0;
// 	if ((keycode.key == MLX_KEY_DOWN || keycode.key == MLX_KEY_S) && keycode.action == MLX_RELEASE)
// 		data->walkDirc = 0;
// 	if ((keycode.key == MLX_KEY_RIGHT) && keycode.action == MLX_RELEASE)
// 		data->turnDirc = 0;
// 	if ((keycode.key == MLX_KEY_LEFT) && keycode.action == MLX_RELEASE)
// 		data->turnDirc = 0;
// }