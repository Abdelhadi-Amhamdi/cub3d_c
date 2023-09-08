/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:26:37 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/08 11:09:02 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

float normalize_angle(float angle)
{
    // printf("angle before nor:%f\n",angle);
    angle = remainder(angle, (M_PI * 2));
    if(angle < 0)
        angle = (M_PI * 2) + angle;
    // printf("angle after nor:%f\n\n",angle);
    return (angle);
}

int check_wall(t_map_data *data, float x, float y)
{
    int check_x;
    int check_y;

    if(x <= 0 || x >= data->win_width || y <= 0 || y >= data->win_height)
        return (1);
    check_x = (int)(floor(x / CUB_SIZE));
    check_y = (int)(floor(y / CUB_SIZE));
    // printf("y:%d x:%d\n",check_y, check_x);
    return (data->map_body[check_y][check_x] == '1');
}

float cal_distance(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

float    cast_horz(t_map_data *data,float angle ,int id, t_line *line)
{    
    (void)id;
    line->yinter = floor(data->player_y / CUB_SIZE) * CUB_SIZE;
    if(data->rays.isFacingDown)
        line->yinter += CUB_SIZE;
    line->xinter = data->player_x + ((line->yinter - data->player_y) / tan(angle));

    line->alpha_y = CUB_SIZE;
    if(data->rays.isFacingUp)
        line->alpha_y *= -1;
    line->alpha_x = CUB_SIZE / tan(angle);
    if(data->rays.isFacingLeft && line->alpha_x > 0)
        line->alpha_x *= -1;
    if (data->rays.isFacingRight && line->alpha_x < 0)
        line->alpha_x *= -1;
    line->horz_x = line->xinter;
    line->horz_y = line->yinter;
    // printf("win_w :%d -- x:%f\n",data->win_width, line->xinter);
    // printf("win_h :%d -- y:%f --- %f\n",data->win_height, line->yinter, line->alpha_y);
    while(line->horz_x >=0 && line->horz_x <= data->win_width && line->horz_y >= 0 && line->horz_y <= data->win_height)
    {
        float xcheck = line->horz_x;
        float ycheck = line->horz_y;
        // printf("win_w :%d -- x:%f\n",data->win_width, xcheck);
        // printf("af win_h :%d -- y:%f --- %f\n",data->win_height, ycheck, line->alpha_y);
        if(data->rays.isFacingUp)
            ycheck -= 1;
        if(check_wall(data, xcheck, ycheck))
        {
            // printf("y:%f x:%f\n",ycheck / CUB_SIZE, xcheck / CUB_SIZE);
            line->h_hitx = xcheck;
            line->h_hity = ycheck;
            break;
        }
        else
        {
            line->horz_x += line->alpha_x;
            line->horz_y += line->alpha_y;
        }
    }
    
   
    float distance = cal_distance(data->player_x, data->player_y, line->horz_x, line->horz_y);
    // draw_line(data,data->plyr_x, data->plyr_y, data->plyr_x + cos(angle) * distance, data->plyr_y + sin(angle) * distance);
    return(distance);
    // printf("%f\n", distance);
}


float    cast_vert(t_map_data *data, float angle, int id, t_line *line)
{
    (void)id;
    line->xinter = floor(data->player_x / CUB_SIZE) * CUB_SIZE;
    if(data->rays.isFacingRight)
        line->xinter += CUB_SIZE;
    line->yinter  = data->player_y + (line->xinter - data->player_x) * tan(angle);

    line->alpha_x = CUB_SIZE;
    if(data->rays.isFacingLeft)
        line->alpha_x *= -1;
    line->alpha_y = line->alpha_x * tan(angle);
    if(data->rays.isFacingUp && line->alpha_y > 0)
        line->alpha_y *= -1;
    else if (data->rays.isFacingDown && line->alpha_y < 0)
        line->alpha_y *= -1;
    line->vert_x = line->xinter;
    line->vert_y = line->yinter;
    while(line->vert_x >=0 && line->vert_x <= data->win_width && line->vert_y >= 0 && line->vert_y <= data->win_height)
    {
        float xcheck = line->vert_x;
        if(data->rays.isFacingLeft)
            xcheck -= 1;
        float ycheck = line->vert_y;
        if(check_wall(data, xcheck, ycheck))
        {
            line->v_hitx = xcheck;
            line->v_hity = ycheck;
            break;
        }
        else
        {
            line->vert_x += line->alpha_x;
            line->vert_y += line->alpha_y;
        }
    }
    float distance = cal_distance(data->player_x, data->player_y, line->vert_x, line->vert_y);
    // draw_line(data,data->plyr_x, data->plyr_y, data->plyr_x + cos(angle) * distance, data->plyr_y + sin(angle) * distance);
    
    return (distance);

}

void    check_angle_dir(t_map_data *data, float angle, int id)
{
    (void)id;
    data->rays.isFacingDown = 0;
    data->rays.isFacingLeft = 0;
    data->rays.isFacingRight = 0;
    data->rays.isFacingUp = 0;
    if(angle > M_PI)
        data->rays.isFacingUp = 1;
    data->rays.isFacingDown = !data->rays.isFacingUp;
    if(angle > (M_PI / 2) && angle < ((3 * M_PI) / 2))
        data->rays.isFacingLeft = 1;
    data->rays.isFacingRight = !data->rays.isFacingLeft;
    data->rays.is_verthit = 0;

}

void    raycasting(t_map_data *data)
{
    int id;
    t_line line;
    float vert_dis;
    float horz_dis;
    
    float  rayangle = data->roatAngle - (data->fov / 2);
    id = 0;
    while(id < data->num_rays)
    {
        // if(id == (data->num_rays / 2))
        // {
            rayangle = normalize_angle(rayangle);
            // data->rays[id].rayAngle = rayangle;
            data->rays.rayAngle = rayangle;
            check_angle_dir(data, rayangle, id);
            horz_dis = cast_horz(data, rayangle ,id, &line);
            vert_dis =  cast_vert(data,rayangle, id, &line);
            if(vert_dis < horz_dis)
            {
                data->rays.Distance = vert_dis;
                data->rays.is_verthit = 1;
                data->rays.x_hit = line.v_hitx;
                data->rays.y_hit = line.v_hity;
                // draw_line(data, data->player_x * MINI_MAP, data->player_y * MINI_MAP, \
                // (data->player_x + (cos(rayangle) * vert_dis)) * MINI_MAP, (data->player_y + (sin(rayangle) * vert_dis)) * MINI_MAP);
            }
            else
            {
                data->rays.Distance = horz_dis;
                data->rays.x_hit = line.h_hitx;
                data->rays.y_hit = line.h_hity;
                // draw_line(data, data->player_x * MINI_MAP, data->player_y * MINI_MAP, \
                // (data->player_x + cos(rayangle) * horz_dis) * MINI_MAP, (data->player_y + sin(rayangle) * horz_dis) * MINI_MAP);
            }
        // }
        wall_projection(data, id);
        rayangle += (data->fov / data->num_rays);
        id++;
    }
} 
