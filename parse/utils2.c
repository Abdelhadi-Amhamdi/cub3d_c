/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:14:57 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/09/06 15:16:43 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	destroy_map_data(t_map_data *data)
{
	if (!data)
		return ;
	free (data->south_img_path);
	free (data->west_img_path);
	free (data->east_img_path);
	free (data->north_img_path);
	ft_free(data->map_body);
	free (data);
}
