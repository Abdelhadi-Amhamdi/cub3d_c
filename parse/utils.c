/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:58:55 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/13 03:08:33 by aamhamdi         ###   ########.fr       */
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

char	**read_map_file(char *file_name)
{
	int		fd;
	char	*line;
	char	*map;
	char	**map_body;
	char	*tmp;

	fd = open(file_name, O_RDONLY, 0644);
	if (fd == -1)
		return (NULL);
	map = calloc(1, 1);
	line = get_next_line(fd);
	while (line)
	{
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
