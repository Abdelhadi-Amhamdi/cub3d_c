/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:33:53 by aagouzou          #+#    #+#             */
/*   Updated: 2023/07/31 20:08:30 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cleaner(char *buff, char *data)
{
	free(buff);
	free(data);
	data = NULL;
	return (NULL);
}

int	ft_strxlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strxdup(char *s)
{
	int		len;
	char	*str;
	int		i;

	len = ft_strxlen(s);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strxlcpy(char *dest, char *src, int len)
{
	int	src_len;
	int	i;

	i = 0;
	src_len = ft_strxlen(src);
	if (len == 0)
		return (src_len);
	while (src[i] != '\0' && i < len - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

char	*ft_join(char *s1, char *s2)
{
	int		len;
	char	*data;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strxlen(s1) + ft_strxlen(s2);
	data = malloc(len + 1);
	if (!data)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		data[i++] = s1[j++];
	j = 0;
	while (s2[j])
		data[i++] = s2[j++];
	data[i] = '\0';
	free(s1);
	return (data);
}
