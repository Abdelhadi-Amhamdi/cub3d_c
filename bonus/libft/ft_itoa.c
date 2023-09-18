/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:29:53 by aagouzou          #+#    #+#             */
/*   Updated: 2022/11/01 10:51:53 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_putxstr(char *p, int num, int i)
{
	p[i--] = '\0';
	if (num < 0)
	{
		num *= -1;
		p[0] = '-';
	}
	while (num)
	{
		p[i--] = (num % 10) + 48;
		num /= 10;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	int		l;
	char	*p;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	l = ft_len(n);
	p = malloc(sizeof(char) * (l + 1));
	if (!p)
		return (NULL);
	p = ft_putxstr(p, n, l);
	return (p);
}
