/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:56:34 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/20 21:56:36 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_sizes(int *h_size, int *w_size, int from, char *buf)
{
	char	*p;

	p = buf + from;
	*h_size = ft_atoi(p);
	while (*p != ' ')
		p++;
	*w_size = ft_atoi(p);
}

int		read_map_size(t_fil *info)
{
	char	*buf;
	int		gnl;

	if ((gnl = get_next_line(0, &buf)) > 0)
	{
		read_sizes(&(info->h_map), &(info->w_map), 8, buf);
		ft_strdel(&buf);
	}
	else
		return (gnl);
	if ((gnl = get_next_line(0, &buf)) > 0)
		ft_strdel(&buf);
	else
		return (gnl);
	return (gnl);
}

int		read_board(t_fil *info)
{
	int		gnl;
	char	*buf;
	int		i;

	i = 0;
	while (i < info->h_map && (gnl = get_next_line(0, &buf)) > 0)
	{
		(info->map)[i] = buf + 4;
		i++;
	}
	return (gnl);
}

int		read_map(t_fil *info)
{
	int		gnl;

	if ((gnl = read_map_size(info)) != 1)
		return (gnl);
	if (!(info->map = (char**)ft_memalloc(sizeof(char*) * (info->h_map + 1))))
		return (-1);
	if ((gnl = read_board(info)) != 1)
		return (gnl);
	if ((gnl = read_tokens(info)) != 1)
		return (gnl);
	return (gnl);
}
