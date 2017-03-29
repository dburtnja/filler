/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:23:37 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/20 21:51:46 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	read_flags(char **p_argv, int *flag)
{
	if (p_argv[0][0] == '-' && p_argv[0][1] == 'c')
		flag[0] = 1;
	if (p_argv[0][0] == '-' && p_argv[0][1] == 't')
		flag[1] = ft_atoi(p_argv[1]);
}

void	check_flag(int *flag, char ***argv, int *argc)
{
	char	**p_argv;

	flag[0] = 0;
	flag[1] = 1;
	p_argv = *argv;
	p_argv++;
	(*argc)--;
	while (*argc > 1)
	{
		read_flags(p_argv, flag);
		(*argc)--;
		p_argv++;
	}
	*argv = p_argv;
}
