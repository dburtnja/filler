#include "libft.h"

void				ft_lstadd_back(t_list **alst, t_list *new)
{
	t_doub_lst	*p;

	p = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
		new->prev = p;
	}
}


