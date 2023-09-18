/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:20:07 by aagouzou          #+#    #+#             */
/*   Updated: 2022/10/29 09:19:50 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*_s1;
	char	*rtn;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	_s1 = (char *)s1;
	i = 0;
	while (check_char(set, _s1[i]))
		i++;
	while (check_char(set, _s1[len - 1]))
		len--;
	if (len == 0 || i == len)
	{
		return (ft_strdup(""));
	}
	rtn = ft_substr(_s1, i, len - i);
	return (rtn);
}
