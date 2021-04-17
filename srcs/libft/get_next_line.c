/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <sfournio@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 07:09:41 by sfournio          #+#    #+#             */
/*   Updated: 2021/04/17 14:13:54 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl2(char *line, char **tmp, int l, char c)
{
	int	i;

	*tmp = malloc(l);
	if (!(*tmp))
		return (-1);
	i = -1;
	while (++i < l - 2)
		(*tmp)[i] = line[i];
	(*tmp)[i] = c;
	(*tmp)[i + 1] = 0;
	return (1);
}

int	get_next_line(char **line)
{
	int		l;
	int		r;
	char	c;
	char	*tmp;

	r = 0;
	l = 1;
	*line = malloc(l);
	if (!(*line))
		return (-1);
	(*line)[0] = 0;
	while (1)
	{
		r = read(0, &c, 1);
		if (r == 0 || c == '\n')
			break ;
		if (gnl2(*line, &tmp, ++l, c) == -1)
		{
			free(*line);
			return (-1);
		}
		free(*line);
		*line = tmp;
	}
	return (r);
}
