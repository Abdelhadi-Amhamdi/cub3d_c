/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:01:25 by aagouzou          #+#    #+#             */
/*   Updated: 2022/10/30 08:53:32 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (!len && c == 0)
		return ((char *)s);
	while (len >= 0)
	{
		if ((char)c == s[len])
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}
