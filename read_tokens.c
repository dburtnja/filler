#include "filler.h"

void	read_string(t_fil *info, char *str, int h)
{
	t_list	*p;
	int 	w;

	w = 0;
	info->tokens = NULL;
	while (info->w_tokens > w)
	{
		if (str[w] != '.')
		{
			p = write_cordinates(h, w, 0);
			ft_lstadd_back(&(info->tokens), p);
		}
		w++;
	}
}

int		read_tokens(t_fil *info)
{
	char	*buf;
	int		gnl;
	int		h;

	h = 0;
	if ((gnl = get_next_line(0, &buf)) > 0)
	{
		read_sizes(&(info->h_tokens), &(info->w_tokens), 6, buf);
		ft_strdel(&buf);
	}
	else
		return (gnl);
	while ((gnl = get_next_line(0, &buf)) > 0 && h < info->h_tokens)
	{
		read_string(info, buf, h);
		ft_strdel(&buf);
		h++;
	}
	return (gnl);
}