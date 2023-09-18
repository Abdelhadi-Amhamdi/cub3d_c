/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:01:48 by aagouzou          #+#    #+#             */
/*   Updated: 2022/10/29 08:58:22 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_res(long long int res, long long int p_res)
{
	if ((res / 10) != p_res)
		return (1);
	return (0);
}

static int	ft_signe(char c, int signe)
{
	if (c == '-')
		signe *= -1;
	return (signe);
}

int	ft_atoi(const char *str)
{
	long long int	res;
	long long int	p_res;
	int				signe;
	int				i;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	signe = ft_signe(str[i], signe);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		p_res = res;
		res = res * 10 + (str[i] - '0');
		if (check_res(res, p_res) && signe == 1)
			return (-1);
		else if (check_res(res, p_res) && signe == -1)
			return (0);
		i++;
	}
	return ((res * signe));
}
