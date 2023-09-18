/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 08:38:58 by aagouzou          #+#    #+#             */
/*   Updated: 2022/10/30 17:17:25 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*_b;
	unsigned char	_c;

	i = 0;
	_c = (unsigned char)c;
	_b = (unsigned char *)b;
	while (i < len)
		_b[i++] = _c;
	return ((void *)_b);
}
