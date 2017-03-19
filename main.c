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
		return (buf[10] - '0');
	perror("Cannot read PLAYER_NUMBER: ");
	return (-1);
}

void	init_info(t_fil *info, int p_n)
{
	info->p_n = p_n;
	info->h_map = 0;
	info->w_map = 0;
	info->h_tokens = 0;
	info->w_tokens = 0;
	info->map = 0;
	info->tokens = 0;
	info->hos_cor = 0;
	info->h_m_tok = 0;
	info->w_m_tok = INT_MAX;
	info->all_target = (int*)ft_memalloc(sizeof(int) * 3);
	(info->all_target)[0] = INT_MAX;
}

int		main(void)
{
	t_fil info;
	int r;

	init_info(&info, 0);
	if ((info.p_n = read_player_nbr()) == -1)
		return (-1);
	while ((r = read_map(&(info))) > 0)
	{
		find_coordinates(&info);
		init_info(&info, info.p_n);
	}
	if (r == -1)
		perror("Cannot read MAP: ");
	return (0);
}