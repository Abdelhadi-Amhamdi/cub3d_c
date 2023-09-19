/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:58:55 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/19 10:14:43 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

int	check_line_helper(char *line, int *data_found)
{
	int	ret;

	ret = check_line(line);
	if (ret == DATA_ITEM && *data_found < 6)
		(*data_found)++;
	else if ((ret == 0 && *data_found > 5 && !(*data_found % 2)))
		(*data_found)++;
	else if (ret == EMPTY_LINE && *data_found > 5 && (*data_found % 2))
		(*data_found)++;
	else if (*data_found == 6 && ret == DATA_ITEM)
		return (print_error(DDATA), 1);
	else if (ret == INVALID_CHAR || (!ret && *data_found < 6))
		return (print_error(NITEM), 1);
	return (0);
}

char	*read_all_map(int fd)
{
	int		data_found;
	char	*map;
	char	*tmp;
	char	*line;

	data_found = 0;
	map = calloc(1, 1);
	line = get_next_line(fd);
	if (!line)
		return (print_error(NMAP), free(map), NULL);
	while (line)
	{
		if (check_line_helper(line, &data_found))
			return (free(map), free(line), NULL);
		tmp = map;
		map = ft_strjoin(map, line);
		free (tmp);
		free (line);
		line = get_next_line(fd);
	}
	if ((data_found % 2) && data_found != 7)
		return (print_error(ELINE), free(map), NULL);
	return (map);
}

char	**read_map_file(char *file_name)
{
	int		fd;
	char	*map;
	char	**map_body;

	fd = open(file_name, O_RDONLY, 0644);
	if (fd == -1)
		return (NULL);
	map = read_all_map(fd);
	if (!map)
		return (close(fd), NULL);
	map_body = ft_split(map, '\n');
	if (!map_body)
		return (free(map), close(fd), NULL);
	free(map);
	return (close (fd), map_body);
}
