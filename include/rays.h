/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:57:21 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/06 16:11:50 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
#define RAYS_H


typedef struct s_line
{
    float xinter;
    float yinter;
    float alpha_x;
    float alpha_y;
    float horz_x;
    float horz_y;
    float vert_x;
    float vert_y;
    float   v_hitx;
    float   v_hity;
    float   h_hitx;
    float   h_hity;
}t_line;

typedef struct s_ray{
    float   rayAngle;
    float x_hit;
    float y_hit;
    int     is_verthit;
    float Distance;
    int isFacingDown;
    int isFacingUp;
    int isFacingRight;
    int isFacingLeft;
    int wallHitContent;
}t_rays;

#endif