/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:00:45 by aagouzou          #+#    #+#             */
/*   Updated: 2023/07/31 20:08:45 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *data)
{
	int	i;

	i = 0;
	if (!data)
		return (-1);
	while (data[i])
	{
		if (data[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_file(int fd, char *data, char *buff)
{
	int		is_line;
	ssize_t	size;

	is_line = 0;
	while (is_line == 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if ((size <= 0 && *data == '\0'))
			return (ft_cleaner(buff, data));
		else if (size == 0 && *data)
			break ;
		else if (size < 0 && *data)
			return (ft_cleaner(buff, data));
		buff[size] = '\0';
		data = ft_join(data, buff);
		if (check_newline(data) != -1)
			is_line = 1;
	}
	free(buff);
	return (data);
}

char	*update_data(char *data)
{
	char	*new_data;
	int		len;
	int		i;

	if (check_newline(data) != -1)
	{
		i = check_newline(data);
		len = ft_strxlen(&data[i + 1]);
		new_data = malloc(len + 1);
		if (!new_data)
			return (NULL);
		ft_strxlcpy(new_data, &data[i + 1], len + 1);
	}
	else
		new_data = NULL;
	free(data);
	return (new_data);
}

char	*get_newline(char *data)
{
	char	*line;
	int		len;

	if (check_newline(data) != -1)
	{
		len = check_newline(data) + 2;
		line = malloc(len);
		if (!line)
			return (NULL);
		ft_strxlcpy(line, data, len);
	}
	else
	{
		line = ft_strxdup(data);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!data)
	{
		data = ft_strxdup("");
		if (!data)
			return (NULL);
	}
	data = read_file(fd, data, buff);
	if (!data)
		return (NULL);
	line = get_newline(data);
	data = update_data(data);
	return (line);
}
