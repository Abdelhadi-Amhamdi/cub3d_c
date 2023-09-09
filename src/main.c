/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:38:19 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/08 15:42:05 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void    get_map_col_row(t_map_data *data)
// {
// 	int col;
// 	int row;

// 	row = 0;
// 	col = 0;
// 	while(data->map_body[row])
// 	{
// 		if((int)ft_strlen(data->map_body[row]) > col)
// 			col = (int)ft_strlen(data->map_body[row]);
// 		row++;
// 	} 
// 	data->cols = col;
// 	data->rows = row;
// }



int	main(int argc, char *argv[])
{
	t_map_data	*map_data;
	t_data 			*data;
	t_player_data	*p_data;
	t_img_data		*img_data;

	if(argc != 2)
		return(0);
	map_data = parser(argc, argv);
	p_data = init_player(map_data);
	img_data = init_images(map_data);
	data = init_data(map_data, p_data, img_data);
	_draw(data);
	// init_data(map_data);
	mlx_loop(data->mlx);
	return (0);
}