//
// Created by Denys on 19.03.2017.
//

#include "filler.h"

int		manhattan_distance(int p1, int p2, int q1, int q2)
{
	int	res1;
	int res2;

	res1 = p1 - q1;
	res1 = res1 < 0 ? -res1 : res1;
	res2 = p2 - q2;
	res2 = res2 < 0 ? -res2 : res2;
	return (res1 + res2);
}

void	write_into_cont(int *cont, int dis, int h, int w)
{
	cont[0] = dis;
	cont[1] = h;
	cont[2] = w;
}

void	write_into_info(t_fil *info, t_list *hos, int h, int w)
{
	int		dis;

	dis = manhattan_distance(h, w, ((int*)(hos->content))[0],
								 ((int*)(hos->content))[1]);
	if (!(info->all_target))
		write_into_cont((info->all_target), dis, h, w);
	if (((info->all_target))[0] > dis)
		write_into_cont((info->all_target), dis, h, w);
}