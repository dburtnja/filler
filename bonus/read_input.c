

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
		if (*buf == 'P')
			ft_putendl(buf);
		else
			print_str(buf);
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