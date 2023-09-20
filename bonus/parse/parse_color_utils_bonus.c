/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:16:03 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/20 22:34:26 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
