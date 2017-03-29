/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:51:07 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/20 21:58:42 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	print_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == 'X')
			ft_putstr(RED"X"RESET);
		else if (str[i] == 'x')
			ft_putstr(YELLOW"X"RESET);
		else if (str[i] == 'O')
			ft_putstr(BLUE"O"RESET);
		else if (str[i] == 'o')
			ft_putstr(GREEN"o"RESET);
		else
			ft_putchar(str[i]);
		i++;
	}
	ft_putendl("");
}

void	print(char *buf)
{
	if (*buf == 'P')
		ft_putendl(buf);
	else
		print_str(buf);
}

int		read_else(t_bon *info)
{
	int		gnl;
	char	*buf;

	buf = NULL;
	while ((gnl = get_next_line(0, &buf)) > 0)
	{
		if (*buf == '<')
			return (1);
		if (buf[3] == 'y')
		{
			if (get_next_line(0, &(info->o)))
				return (-1);
			ft_strdel(&buf);
			return (2);
		}
		if (*buf == '=')
		{
			info->o = buf;
			return (2);
		}
		print(buf);
		ft_strdel(&buf);
	}
	return (gnl);
}

int		read_input(t_bon *info)
{
	ft_putstr(info->header);
	ft_putstr(RESET);
	return (read_else(info));
}
