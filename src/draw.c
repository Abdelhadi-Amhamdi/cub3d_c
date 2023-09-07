/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:36:45 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/06 20:52:31 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void    draw_grid(t_map_data *data, int x, int y, int color)
// {
//     int i;
//     int j;

//     i = 0;
//     while(i < (CUB_SIZE ))
//     {
//         j = 0;
//         while(j < (CUB_SIZE ))
//         {
//             mlx_put_pixel(data->img, (x + i), (y + j) , color );
//             if (j == 0 || i == 0 || j == CUB_SIZE - 1 || i == CUB_SIZE - 1)
//                 mlx_put_pixel(data->img, (x + i), (y + j), 0x0047910F);
//             j++;
//         }
//         i++;
//     }
// }

// void    draw_map(t_map_data *data)
// {
//     int i= 0, j = 0;
//     while(data->map_body[i])
//     {
//         j = 0;
//         while(data->map_body[i][j])
//         {
//             if(data->map_body[i][j] == '1')   
//                 draw_grid(data, (j * CUB_SIZE), (i * CUB_SIZE), 0xFFFFFFFF);
//             else
//                 draw_grid(data, (j * CUB_SIZE), (i * CUB_SIZE), 0x000000FF );
                
//             j++;
//         }
//         i++;
//     }
// }

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