//
// Created by Denys on 20.03.2017.
//

#include "filler.h"
#include <curses.h>

int		main(int argc, char **argv)
{
	char	*buf;

	while (get_next_line(0, &buf) > 0)
	{
		ft_putendl(buf);
		ft_strdel(&buf);
		clear();
	}
	return (0);
}