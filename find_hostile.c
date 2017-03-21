//
// Created by Denys on 16.03.2017.
//

#include "filler.h"


t_list	*write_coordinates(int h, int w, char c, int *win)
{
	int		coor[2];

	coor[0] = h;
	coor[1] = w;
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