//
// Created by Denys on 16.03.2017.
//

#include "filler.h"

t_list	*write_coordinates(int h, int w, char c)
{
	t_list	*new;
	int		coor[3];

	coor[0] = h;
	coor[1] = w;
	coor[2] = c >= 'A' && c <= 'Z' ? 1 : 0;
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
		while (info->w_map > w)
		{
			if ((info->map)[h][w] == c || (info->map)[h][w] == c - 53)
			{
				p = write_coordinates(i, j, c);
				ft_lstadd_back(&head, p);
			}
			j++;
		}
		i++;
	}
	info->hos_cor = head;
}