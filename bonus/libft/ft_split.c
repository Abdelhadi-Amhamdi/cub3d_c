/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:31:24 by aagouzou          #+#    #+#             */
/*   Updated: 2022/11/01 10:53:56 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(const char *s, char c)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wc++;
		i++;
	}
	return (wc);
}

static int	ft_lenxword(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_clean(char **p, int pos)
{
	while (--pos >= 0)
		free(p[pos]);
	free(p);
	return (0);
}

static char	**ft_putxword(char **p, const char *s, char c, int wc)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (i < wc)
	{
		while (*s == c && *s)
			s++;
		len = ft_lenxword(s, c);
		p[i] = (char *)malloc((len + 1) * sizeof(char));
		if (!p[i])
			return (ft_clean(p, i));
		j = 0;
		while (j < len)
			p[i][j++] = *s++;
		p[i++][j] = '\0';
	}
	p[i] = 0;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		wc;

	if (!s)
		return (0);
	wc = ft_words(s, c);
	ptr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!ptr)
		return (NULL);
	ptr = ft_putxword(ptr, s, c, wc);
	return (ptr);
}
