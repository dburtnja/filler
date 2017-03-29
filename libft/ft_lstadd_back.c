/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:39:23 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/20 21:39:25 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*p;

	p = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}
