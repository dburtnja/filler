/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:40:35 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/20 21:44:01 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	lst_free(t_list **lst)
{
	t_list	*p;
	t_list	*temp;

	p = *lst;
	while (p)
	{
		free(p->content);
		temp = p;
		p = p->next;
		free(temp);
	}
	*lst = NULL;
}

void	free_arr(char ***arr, int size)
{
	int		i;
	char	**p_arr;

	i = 0;
	p_arr = *arr;
	while (size > i)
	{
		free(p_arr[i] - 4);
		i++;
	}
	free(p_arr);
	*arr = NULL;
}
