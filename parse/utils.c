/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: original <original@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:58:55 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/16 19:55:06 by original         ###   ########.fr       */
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

int	check_line(char *line)
{
	int	i;

	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) \
	|| !ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3) ||\
	!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (DATA_ITEM);
	else if (line && line[0] == '\n')
		return (EMPTY_LINE);
	else
	{
		i = 0;
		while (line && line[i])
		{
			if (line[i] != '\n' && line[i] != '1' && line[i] != '0' && \
			line[i] != 'N' && line[i] != 'E' && line[i] != 'W' && \
			line[i] != 'S' && line[i] != ' ')
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
	else if ((ret == 0 && *data_found == 6))
		(*data_found)++;
	else if (ret == EMPTY_LINE && *data_found == 7)
		return (1);
	else if (*data_found == 6 && ret == DATA_ITEM)
		return (print_error(DDATA), 1);
	else if (ret == INVALID_CHAR)
		return (1);
	return (0);
}

char	**read_map_file(char *file_name)
{
	int		fd;
	char	*line;
	char	*map;
	char	**map_body;
	char	*tmp;
	int		data_found;
	
	data_found = 0;
	fd = open(file_name, O_RDONLY, 0644);
	if (fd == -1)
		return (NULL);
	map = calloc(1, 1);
	line = get_next_line(fd);
	while (line)
	{
		if (check_line_helper(line, &data_found))
			return (NULL);
		tmp = map;
		map = ft_strjoin(map, line);
		free (tmp);
		free (line);
		line = get_next_line(fd);
	}
	map_body = ft_split(map, '\n');
	if (!map_body)
		return (free(map), NULL);
	free(map);
	return (map_body);
}

int	ft_tabs_len(char **map)
{
	int	size;

	size = 0;
	while (map[size])
		size++;
	return (size);
}

char	**ft_tabs_dup(char **map)
{
	int		size;
	char	**new_map;
	int		index;

	size = ft_tabs_len(map);
	index = 0;
	new_map = malloc(sizeof(char *) * (size + 1));
	if (!new_map)
		return (NULL);
	while (map[index])
	{
		new_map[index] = ft_strdup(map[index]);
		index++;
	}
	new_map[index] = NULL;
	return (new_map);
}
