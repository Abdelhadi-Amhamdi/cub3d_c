/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:49:09 by aagouzou          #+#    #+#             */
/*   Updated: 2022/11/01 10:51:35 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	total_size;

	total_size = count * size;
	if (count != 0 && size != (total_size / count))
		return (0);
	p = malloc(total_size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, total_size);
	return (p);
}
