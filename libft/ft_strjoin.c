/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:33:44 by aagouzou          #+#    #+#             */
/*   Updated: 2023/08/09 21:30:20 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join_str(const char *s1, const char *s2, char *str)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	k = 0;
	while (s2[k])
		str[i++] = s2[k++];
	str[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if(!s1)
		s1 = ft_strdup("");
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	join_str(s1, s2, str);
	return (str);
}
