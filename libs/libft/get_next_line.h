/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <aagouzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:33:47 by aagouzou          #+#    #+#             */
/*   Updated: 2023/07/31 20:08:56 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strxlen(char *s);
char	*get_next_line(int fd);
char	*ft_join(char *s1, char *s2);
char	*ft_strxdup(char *s);
int		ft_strxlcpy(char *dest, char *src, int len);
char	*ft_cleaner(char *buff, char *data);
#endif