/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:55:47 by aagouzou          #+#    #+#             */
/*   Updated: 2022/11/01 10:44:55 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;
	size_t	j;

	slen = ft_strlen(src);
	if (!dst && !dstsize)
		return (0);
	dlen = ft_strlen(dst);
	if (dstsize <= dlen)
		return (dstsize + slen);
	j = dlen;
	i = 0;
	while (src[i] && j < dstsize - 1)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}
