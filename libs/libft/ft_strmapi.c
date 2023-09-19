/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:31:35 by aagouzou          #+#    #+#             */
/*   Updated: 2022/10/29 09:18:01 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rtn;
	int		in;
	int		len;

	if (!f || !s)
		return (NULL);
	len = ft_strlen(s);
	rtn = (char *)malloc((len + 1) * sizeof(char));
	if (!rtn)
		return (NULL);
	in = 0;
	while (s[in])
	{
		rtn[in] = f(in, s[in]);
		in++;
	}
	rtn[in] = '\0';
	return (rtn);
}
