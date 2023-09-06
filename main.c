/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:59:09 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/06 16:02:12 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	get_responive_sizes(int *width, int *height, t_map_data *data)
{
	*width = data->cols * CUB_SIZE;
	if (W_WIDTH < *width)
		*width = W_WIDTH;
	*height = data->rows * CUB_SIZE;
	if (W_HEIGHT < *height)
		*height = W_HEIGHT;
}

int	main(int ac, char **av)
{
	t_map_data	*map_data;
	int			width;
	int			height;

	map_data = parser(ac, av);
	get_responive_sizes(&width, &height, map_data);
	return (0);
}