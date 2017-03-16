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

int		read_player_nbr(void)
{
	char	*buf;

	if (get_next_line(0, &buf))
		return (buf[10] + '0');
	perror("Cannot read PLAYER_NUMBER: ");
	return (-1);
}

int		main(void)
{
	t_fil info;
	int r;

	if ((info.p_n = read_player_nbr()) == -1)
		return (-1);
	while ((r = read_map(&(info))) > 0);
	find_coordinates(&info);
	if (r == -1)
		perror("Cannot read MAP: ");
	return (0);
}