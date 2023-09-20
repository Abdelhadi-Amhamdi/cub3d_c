/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:59:57 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/20 22:33:20 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free(char **tabs)
{
	int	i;

	i = 0;
	while (tabs[i])
	{
		free(tabs[i]);
		i++;
	}
	free (tabs);
}

void	init_data_map(t_map_data *data)
{
	data->ceil_color = NULL;
	data->floor_color = NULL;
	data->ceil_rgb = 0;
	data->floor_rgb = 0;
	data->east_img_path = NULL;
	data->west_img_path = NULL;
	data->south_img_path = NULL;
	data->north_img_path = NULL;
	data->map_body = NULL;
}

int	is_data(char *str)
{
	if (is_valid_data(str, "NO ", 3) || is_valid_data(str, "SO ", 3) \
	|| is_valid_data(str, "WE ", 3) || is_valid_data(str, "EA ", 3) || \
	is_valid_data(str, "F ", 2) || is_valid_data(str, "C ", 2))
		return (1);
	return (0);
}

int	is_valid_char(char c)
{
	if (c != '\n' && c != '1' && c != '0' && \
	c != 'N' && c != 'E' && c != 'W' && \
	c != 'S' && c != ' ')
		return (0);
	return (1);
}

int	check_line(char *line)
{
	int	i;

	if (is_data(line))
		return (DATA_ITEM);
	else if (line && line[0] == '\n')
		return (EMPTY_LINE);
	else
	{
		i = 0;
		while (line && line[i])
		{
			if (!is_valid_char(line[i]))
				return (INVALID_CHAR);
			i++;
		}
	}
	return (0);
}
