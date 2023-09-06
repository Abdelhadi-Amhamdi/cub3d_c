/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:38:19 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/06 16:16:28 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char *argv[])
{
    t_data *data;
	t_map_data *map;

    if(argc != 2)
        return(0);
    map = parser(argc, argv);
	data = (t_data *)malloc (sizeof(t_data));
	if(!data)
		return (0);
	raycasting(data);
    // data.map = get_map(argv[1]);
    // init_data(&data);
    // mlx_loop(data.mlx);
}