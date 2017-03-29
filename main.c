/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:56:28 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/21 15:00:23 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		read_player_nbr(void)
{
	char	*buf;
	int		s;

	if (get_next_line(0, &buf))
	{
		s = buf[10] - '0';
		ft_strdel(&buf);
		return (s);
	}
	perror("Cannot read PLAYER_NUMBER: ");
	return (-1);
}

void	init_info(t_fil *info)
{
	info->p_n = 0;
	info->h_map = 0;
	info->w_map = 0;
	info->h_tokens = 0;
	info->w_tokens = 0;
	info->map = NULL;
	info->tokens = NULL;
	info->hos_cor = NULL;
	info->h_m_tok = 0;
	info->w_m_tok = INT_MAX;
	info->all_target = (int*)ft_memalloc(sizeof(int) * 3);
	(info->all_target)[0] = INT_MAX;
	info->win = 0;
}

void	free_info(t_fil *info, int p_n)
{
	free_arr(&(info->map), info->h_map);
	info->p_n = p_n;
	info->h_map = 0;
	info->w_map = 0;
	info->h_tokens = 0;
	info->w_tokens = 0;
	lst_free(&(info->tokens));
	lst_free(&(info->hos_cor));
	info->h_m_tok = 0;
	info->w_m_tok = INT_MAX;
	(info->all_target)[0] = INT_MAX;
	(info->all_target)[1] = 0;
	(info->all_target)[2] = 0;
	info->win = 0;
}

int		main(void)
{
	t_fil	info;
	int		r;

	init_info(&info);
	if ((info.p_n = read_player_nbr()) == -1)
		return (-1);
	while ((r = read_map(&(info))) > 0)
	{
		find_coordinates(&info);
		free_info(&info, info.p_n);
	}
	if (r == -1)
		perror("Cannot read MAP: ");
	free(info.all_target);
	return (0);
}
