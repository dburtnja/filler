//
// Created by Denys on 16.03.2017.
//

#include "filler.h"

int		comp_char(char c, int p_nbr)
{
	char	p_s;
	char	p_b;

	p_s = (char)(p_nbr == 1 ? 'o' : 'x');
	p_b = (char)(p_nbr == 1 ? 'O' : 'X');
	if (c == p_b || c == p_s)
		return (1);
	return (0);
}

void	print_coordinates(int h, int w)
{
	ft_putnbr(w);
	ft_putstr(" ");
	ft_putnbr(h);
	ft_putendl("");
}

void	find_coordinates(t_fil *info)
{
	find_hostile(info, (char)(info->p_n == 1 ? 'x' : 'o'));
	find_place(info);
}