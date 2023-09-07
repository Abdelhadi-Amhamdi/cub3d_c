/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:59:36 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/07 14:19:14 by aamhamdi         ###   ########.fr       */
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
#include "/Users/aamhamdi/MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#include "parsing.h"

typedef struct s_rect
{
	int			x;
	int			y;
	int			width;
	int			height;
	uint32_t	color;
}	t_rect;

void    init_data(t_map_data *data);
void    ft_error(char *error);
void    hook_handler(void   *param);
void    draw_map(t_map_data *data);
void    draw_plyr(t_map_data *data);
void    key_handler(mlx_key_data_t keycode, void    *param);
void    draw_line(t_map_data    *data, int x0, int y0, int x1, int y1);
void    raycasting(t_map_data *data);
int     check_wall(t_map_data *data, float x, float y);
void    wall_projection(t_map_data *data);

void	_draw_map(t_map_data *data);
float normalize_angle(float angle);
#endif