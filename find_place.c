/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:47:01 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/21 16:49:04 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		try_put_tokens(t_fil *info, int h, int w)
{
	t_list	*p;
	char	**map;
	int		h_t;
	int		w_t;
	int		my;

	my = 0;
	p = info->tokens;
	map = info->map;
	while (p)
	{
		h_t = ((int*)(p->content))[0] + h;
		w_t = ((int*)(p->content))[1] + w;
		if (h_t < 0 || w_t < 0 || h_t >= info->h_map || w_t >= info->w_map)
			return (0);
		if (comp_char(map[h_t][w_t], info->p_n == 1 ? 2 : 1))
			return (0);
		if (comp_char(map[h_t][w_t], info->p_n))
			my++;
		p = p->next;
	}
	if (my != 1)
		return (0);
	return (1);
}

int		check_one_hostage(t_list *hos, t_fil *info, int m)
{
	int		h;
	int		w;
	int		f;

	f = 0;
	h = ((int*)(hos->content))[0] - m;
	while (h <= ((int*)(hos->content))[0] + m)
	{
		w = ((int*)(hos->content))[1] - m;
		while (w <= ((int*)(hos->content))[1] + m)
		{
			if (try_put_tokens(info, h, w))
			{
				write_into_info(info, hos, h, w);
				f++;
			}
			w++;
		}
		h++;
	}
	return (f);
}

void	find_place(t_fil *info)
{
	t_list	*p;
	int		m;
	int		f;
	int		m_max;

	f = 0;
	m = 1;
	m_max = (info->w_map > info->h_map ? info->w_map : info->h_map);
	while (m < m_max)
	{
		p = info->hos_cor;
		while (p)
		{
			f += check_one_hostage(p, info, m);
			p = p->next;
			if (info->win != 1)
				break ;
		}
		m += f != 0 ? m_max : 1;
	}
	if (f != 0)
		print_coordinates((info->all_target)[1] - info->h_m_tok,
			(info->all_target)[2] - info->w_m_tok);
	else
		ft_putendl_fd("0 0", 1);
}
