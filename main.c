/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:56:28 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/15 16:56:50 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

int		read_player_nbr(void)
{
	char	*buf;

	if (get_next_line(0, &buf))
		return (buf[10] + '0');
	perror("Cannot read PLAYER_NUMBER: ");
	return (-1);
}

/*
int		read_map(t_fil *info)
{
	ft_putendl_fd(info->str);
}*/

int		main(void)
{
	t_fil info;
	int gnl;

	int fd = open("maps.txt", O_RDWR | O_TRUNC | O_CREAT, 0777);

	if ((info.p_n = read_player_nbr()) == -1)
		return (-1);

	ft_putnbr_fd(info.p_n, fd);

	while ((gnl = get_next_line(0, &(info.str))) > 0)
		ft_putendl_fd(info.str, fd);
	if (gnl == -1)
		perror("Cannot read MAP: ");
	close(fd);
	return (0);
}