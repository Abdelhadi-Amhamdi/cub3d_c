/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:59:36 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/06 16:11:59 by aagouzou         ###   ########.fr       */
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
#include "../MLX42/include/MLX42/MLX42.h"
#include "./parsing.h"
#include "./rays.h"
#include "../libft/libft.h"

#define MAP 0.5
#define WIN_H 1000
#define WIN_W 1600

typedef struct s_data{
    char **map;
    int row_num;
    int col_num;
    int     grid;
    int win_height;
    int win_width;
    int num_rays;
    float   plyr_x;
    float   plyr_y;
    float   turnDirc;
    float   walkDirc;
    float   roatAngle;
    float   walkSpeed;
    float   turnSpeed;
    float   fov;
    t_rays  *rays;
    mlx_t	*mlx;
    mlx_image_t	*img;
    mlx_texture_t *texture;
    mlx_image_t	*plyr;
}t_data;

void    init_data(t_data *data);
void    ft_error(char *error);
void    hook_handler(void   *param);
void    draw_map(t_data *data);
void    draw_plyr(t_data *data);
void    key_handler(mlx_key_data_t keycode, void    *param);
void    draw_line(t_data    *data, int x0, int y0, int x1, int y1);
void    raycasting(t_data *data);
int check_wall(t_data *data, float x, float y);
void    wall_projection(t_data *data);
#endif