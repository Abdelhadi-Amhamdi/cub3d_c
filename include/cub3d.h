/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:59:36 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/09 18:17:58 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include <math.h>
#include <limits.h>
// #include "/Users/original/MLX42/include/MLX42/MLX42.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#include "parsing.h"

typedef	struct s_player_data
{
	int		walkSpeed;
	float	turnSpeed;
	int		turnDirc;
	int		walkDirc;
	float	player_Angle;
	float	player_x;
	float	player_y;
} t_player_data;

typedef	struct s_img_data
{
	mlx_texture_t *south;
	mlx_texture_t *north;
	mlx_texture_t *west;
	mlx_texture_t *east;
} t_img_data;

typedef struct s_rect
{
	int			x;
	int			y;
	int			width;
	int			height;
	uint32_t	color;
}	t_rect;

typedef	struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	float			fov;
	int				num_rays;
	int				window_width;
	int				window_height;
	t_player_data	*p_data;
	t_img_data		*img_data;
} t_data;


// init
t_img_data		*init_images(t_map_data *map_data);
t_data			*init_data(t_map_data *map_data, \
t_player_data *p_data, t_img_data *m_data);
t_player_data	*init_player(t_map_data *map_data);
float			player_angle(t_map_data *map_data);
void			get_responive_sizes(t_data *data, t_map_data *map_data);

// void    init_data(t_map_data *data);
// void    ft_error(char *error);
// void    hook_handler(void   *param);
// void    draw_map(t_map_data *data);
// void    draw_plyr(t_map_data *data);
// void    key_handler(mlx_key_data_t keycode, void    *param);
// void    draw_line(t_map_data    *data, int x0, int y0, int x1, int y1);
void    raycasting(t_data *data);
// int     check_wall(t_map_data *data, float x, float y);
// void    wall_projection(t_map_data *data, int id);

// void	_draw_map(t_map_data *data);
// float normalize_angle(float angle);
void	_draw(t_data *data, t_map_data *m_data);
void	_draw_map(t_map_data *m_data, t_data *data);
#endif