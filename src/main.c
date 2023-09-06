/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:38:19 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/06 20:10:02 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    get_map_col_row(t_map_data *data)
{
    int col;
    int row;

    row = 0;
    col = 0;
    while(data->map_body[row])
    {
        if((int)ft_strlen(data->map_body[row]) > col)
            col = (int)ft_strlen(data->map_body[row]);
        row++;
    } 
    data->cols = col;
    data->rows = row;
}

void	get_responive_sizes(t_map_data *data)
{
    get_map_col_row(data);
	data->win_width = data->cols * CUB_SIZE;
	// if (W_WIDTH < data->win_width)
	// 	data->win_width = W_WIDTH;
	data->win_height = data->rows * CUB_SIZE;
	// if (W_HEIGHT < data->win_height)
	// 	data->win_height = W_HEIGHT;
}

int	main(int argc, char *argv[])
{
	t_map_data	*map_data;
    
    if(argc != 2)
        return(0);
	map_data = parser(argc, argv);
	get_responive_sizes(map_data);
	init_data(map_data);
	mlx_loop(map_data->mlx);
	return (0);
}