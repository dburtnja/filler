//
// Created by Denys on 17.03.2017.
//
#include "filler.h"

int		try_put_tokens(t_fil *info, int h, int w)
{
	t_list	*p;
	char	**map;
	int 	h_t;
	int 	w_t;
	int		my;

	my = 0;
	p = info->tokens;
	map = info->map;
	while (p)
	{
		h_t = ((int*)(p->content))[0] + h;
		w_t = ((int*)(p->content))[1] + w;
		if (h_t < 0 || w_t < 0 || h_t > info->h_map || w_t > info->w_map)
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
	int 	w;

	h = ((int*)(hos->content))[0] - m;
	w = ((int*)(hos->content))[1] - m;
	while (h <= ((int*)(hos->content))[0] + m)
	{
		while (w <= ((int*)(hos->content))[1] + m)
		{
			if (try_put_tokens(info, h, w))
			{
				print_coordinates(h, w);
				return (1);
			}
			w++;
		}
		h++;
	}
	return (0);
}

void	find_place(t_fil *info)
{
	t_list	*p;
	int		m;
	int		m_max;

	m = 1;
	m_max = (info->w_map > info->h_map ? info->w_map : info->h_map) / 2;
	while (m < m_max)
	{
		p = info->hos_cor;
		while (p)
		{
			if (check_one_hostage(info->hos_cor, info, m))
				return ;
			p = p->next;
		}
		m++;
	}
	ft_putendl("Cannot place anywhere");
}