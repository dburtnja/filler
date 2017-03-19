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

void	print_coordinates(int x, int y)
{
	x = 22;
	y = 77;
	ft_putnbr_fd(222, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(7777, 1);
	ft_putendl_fd("", 1);
}

void	find_coordinates(t_fil *info)
{
	find_hostile(info, (char)(info->p_n == 1 ? 'x' : 'o'));
	find_place(info);
}