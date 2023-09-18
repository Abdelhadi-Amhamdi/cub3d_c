/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:59:36 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/18 21:59:06 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <limits.h>
# include "/Users/aamhamdi/MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "parsing.h"

# define W_WIDTH 1600
# define W_HEIGHT 1000
# define MINI_MAP 0.3
# define CUB_SIZE 64
# define COSTUM_SIZE 6

# define NORMAL_MAP 1
# define COSUTM_MAP 2
# define NONE_MAP 3

typedef struct s_line
{
	float	xinter;
	float	yinter;
	float	delta_x;
	float	delta_y;
	float	next_x;
	float	next_y;
	float	v_hitx;
	float	v_hity;
	float	h_hitx;
	float	h_hity;
	float	v_dis;
	float	h_dis;
}	t_line;

typedef struct s_ray
{
	float	wall_height;
	float	rayangle;
	float	x_hit;
	float	y_hit;
	int		is_verthit;
	float	distance;
	int		isdown;
	int		isup;
	int		isright;
	int		isleft;
}	t_ray;

typedef struct s_player_data
{
	int		walkspeed;
	int		more_speed;
	float	turnspeed;
	int		turndirc;
	int		walkdirc;
	int		move_dirc;
	float	player_angle;
	float	player_x;
	float	player_y;
}	t_player_data;

typedef struct s_img_data
{
	mlx_texture_t	*south;
	mlx_texture_t	*north;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
}	t_img_data;

typedef struct s_rect
{
	uint32_t	color;
	int			x;
	int			y;
	int			width;
	int			height;
}	t_rect;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	float			fov;
	int				mouse_x;
	int				mouse_y;
	int				map_type;
	int				num_rays;
	int				window_width;
	int				window_height;
	t_ray			ray;
	t_player_data	*p_data;
	t_img_data		*img_data;
	t_map_data		*map_data;
}	t_data;

typedef struct s_mini_map
{
	int			start_x;
	int			end_x;
	int			start_y;
	int			end_y;
	uint32_t	color;
}	t_mini_map;

typedef struct s_txtr_data
{
	uint32_t	color;
	int			x_offset;
	int			y_offset;
	double		x_step;
	double		y_step;
	double		first_pixel;
}	t_txtr_data;

// init
t_img_data		*init_images(t_map_data *map_data);
t_data			*init_data(t_map_data *map_data, t_player_data *p_data, \
t_img_data	*m_data);
t_player_data	*init_player(t_map_data *map_data);
t_rect			init_rect(int x, int y, int size, char item);

// utils
float			player_angle(t_map_data *map_data);
void			get_responive_sizes(t_data *data, t_map_data *map_data);

//raycasting
void			raycasting(t_data *data, t_map_data *m_data);
void			check_angle_dir(t_data *data, float angle, int id);
float			cal_distance(float x1, float y1, float x2, float y2);
int				check_wall(t_data *data, t_map_data *m_data, float x, float y);
float			normalize_angle(float angle);
void			wall_projection(t_data *data, int id);
void			init_ray_attr(t_data *data, t_line *line);

void			draw_line(t_data *data, t_line *line);
void			_draw(t_data *data, t_map_data *m_data);
void			_draw_map(t_map_data *m_data, t_data *data);
int				render_rect(t_rect rect, t_data *data);
void			_draw_player(t_data *data, t_mini_map *map);
void			coloriez(t_data *data);

// clean
void			ft_clean(void *d);
void			destroy_m_data(t_map_data *data);
void			destroy_imgs_data(t_img_data *data);

// hook
void			hook(t_data *data);
void			map_hook_helper(t_data *data);
void			_update_data(t_data *data);
#endif