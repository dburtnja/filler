/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:38:30 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/20 21:38:33 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_putnbr_fd(x, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(y, 1);
	ft_putendl_fd("", 1);
}

void	find_coordinates(t_fil *info)
{
	find_hostile(info, (char)(info->p_n == 1 ? 'x' : 'o'));
	find_place(info);
}
