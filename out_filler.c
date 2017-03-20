//
// Created by Denys on 20.03.2017.
//

#include "filler.h"

int		main(int argc, char **argv)
{
	char	*buf;
	int		i;

	while (get_next_line(0, &buf) > 0)
	{
		ft_putendl(buf);
		ft_putendl(buf);
		ft_putendl(buf);
		ft_putendl(buf);
		ft_putendl(buf);
		ft_putendl(buf);
		ft_putendl(buf);
		ft_putendl(buf);
		ft_putendl(buf);
		ft_putendl(buf);
		ft_putendl(buf);
		ft_putendl(buf);
		i = 10000000;
		while (i > 0)
			i--;
		ft_strdel(&buf);
		ft_putstr("\033[2J");
		ft_putstr("\033[0;0f");
	}
	return (0);
}
