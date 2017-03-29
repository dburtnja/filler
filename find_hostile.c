/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hostile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:58:09 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/21 19:27:21 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_list	*write_coordinates(int h, int w, char c, int *win)
{
	int	coor[3];

	coor[0] = h;
	coor[1] = w;
	coor[2] = c >= 'a' && c <= 'z' ? 0 : 1;
	if (win && c >= 'a' && c <= 'z')
		*win = 1;
	return (ft_lstnew((void*)&coor[0], sizeof(coor)));
}

void	find_hostile(t_fil *info, char c)
{
	int		h;
	int		w;
	t_list	*head;
	t_list	*p;

	head = NULL;
	h = 0;
	while (info->h_map > h)
	{
		w = 0;
		while (info->w_map > w)
		{
			if ((info->map)[h][w] == c || (info->map)[h][w] == c - 32)
			{
				p = write_coordinates(h, w, c, &(info->win));
				ft_lstadd_back(&head, p);
			}
			w++;
		}
		h++;
	}
	info->hos_cor = head;
}
