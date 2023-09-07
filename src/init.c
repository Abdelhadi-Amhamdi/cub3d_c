/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:41:47 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/06 21:07:22 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    get_plyr_pos(t_map_data *data, char **map)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				data->player_x = (j * CUB_SIZE);
				data->player_y = (i * CUB_SIZE);
			}
			j++;
		}
		i++;
	}
}

void   set_plyr_attr(t_map_data *data)
{
	get_plyr_pos(data, data->map_body);
	data->roatAngle = (M_PI / 2);;
	data->walkDirc = 0;
	data->turnSpeed = 2 * (M_PI / 180);
	data->walkSpeed = 2;
	data->turnDirc = 0;
	data->fov = 60 * (M_PI / 180);
}

void    init_data(t_map_data *data)
{
	set_plyr_attr(data);
	data->texture = mlx_load_png("./sci-fi.png");
	data->num_rays = data->win_width;
	data->rays = (t_rays *)malloc (sizeof(t_rays) * data->num_rays);
	if(!data->rays)
		ft_error("error: failed to malloc");
	data->mlx = mlx_init(data->win_width,data->win_height, "cub3d", 1);
	if(!data->mlx)
		ft_error("error: failed to init mlx");
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	if(!data->img)
		ft_error("error: mlx_new_image / image to win failed");
	// printf("%d %d\n",data->player_x, data->player_y);
	_draw_map(data);
	mlx_image_to_window (data->mlx, data->img, 0, 0);
	mlx_key_hook(data->mlx,key_handler,data);
	mlx_loop_hook(data->mlx,hook_handler,data);
}