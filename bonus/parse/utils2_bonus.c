/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:14:57 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/20 13:29:50 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	destroy_map_data(t_map_data *data)
{
	if (!data)
		return ;
	free (data->south_img_path);
	free (data->west_img_path);
	free (data->east_img_path);
	free (data->north_img_path);
	free (data->ceil_color);
	free (data->floor_color);
	if (data->map_body)
		ft_free(data->map_body);
	free (data);
}

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

void	print_error(char *error)
{
	printf("ERROR\n%s\n", error);
}

int	check_player(t_map_data *data)
{
	if (data->player_x == 0 || data->player_y == 0)
		return (1);
	if (!data->map_body[data->player_y][data->player_x + 1] \
	|| data->map_body[data->player_y][data->player_x + 1] == ' ')
		return (1);
	if (!data->map_body[data->player_y][data->player_x - 1] \
	|| data->map_body[data->player_y][data->player_x - 1] == ' ')
		return (1);
	if (!data->map_body[data->player_y + 1][data->player_x] \
	|| data->map_body[data->player_y + 1][data->player_x] == ' ')
		return (1);
	if (!data->map_body[data->player_y - 1][data->player_x] \
	|| data->map_body[data->player_y - 1][data->player_x] == ' ')
		return (1);
	return (0);
}

int	check_each_item(char item)
{
	return (item != WALL && item != N_PLAYER && item \
	!= WH_SAPCE && item != EMPTY && item != S_PLAYER \
	&& item != E_PLAYER && item != W_PLAYER);
}
