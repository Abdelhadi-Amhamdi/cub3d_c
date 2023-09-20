/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:09:25 by aagouzou          #+#    #+#             */
/*   Updated: 2023/09/20 22:33:25 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calc_color(unsigned int *rgb, int r, int g, int b)
{
	*rgb += r;
	*rgb <<= 8;
	*rgb += g;
	*rgb <<= 8;
	*rgb += b;
}

int	is_valid_data(char *str, char *cmp, size_t len)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	return (!ft_strncmp(str + i, cmp, len));
}
