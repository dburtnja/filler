/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:52:22 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/20 21:52:25 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"
#include <time.h>

int		read_header(t_bon *info)
{
	int		i;
	char	*buf;
	char	*temp;
	int		gnl;

	i = 9;
	while (i > 0 && (gnl = get_next_line(0, &buf)) > 0)
	{
		temp = info->header;
		info->header = ft_strjoin(temp, buf);
		ft_strdel(&temp);
		temp = info->header;
		info->header = ft_strjoin(temp, "\n");
		ft_strdel(&temp);
		ft_strdel(&buf);
		i--;
	}
	return (gnl);
}

int		print_winer(t_bon *info)
{
	char	*o;
	char	*x;

	o = info->o;
	if (get_next_line(0, &x) != 1)
		return (-1);
	if (ft_atoi(o + 10) > ft_atoi(x + 10))
		ft_putstr(BLUE"Player 1");
	else
		ft_putstr(RED"Player 2");
	ft_putendl(" WIN!!!"RESET);
	ft_putendl(o);
	ft_putendl(x);
	ft_strdel(&o);
	ft_strdel(&x);
	return (0);
}

int		main(int argc, char **argv)
{
	long	time;
	t_bon	info;
	int		gnl;

	info.flag[1] = 1;
	if (argc > 1)
		check_flag(&(info.flag[0]), &argv, &argc);
	info.header = ft_strdup(RED);
	if ((gnl = read_header(&info)) != 1)
		return (gnl);
	while (gnl == 1)
	{
		ft_putstr(CLEARE);
		ft_putstr(TO_BEGIN);
		gnl = read_input(&info);
		time = 25000000 * info.flag[1];
		nanosleep((const struct timespec[]){{0, time}}, NULL);
	}
	if (gnl == 2)
		gnl = print_winer(&info);
	ft_strdel(&info.header);
	if (gnl < 0)
		return (gnl);
	return (0);
}
