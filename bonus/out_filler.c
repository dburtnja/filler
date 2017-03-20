

#include "../filler.h"

int		read_header(t_bon *info)
{
	int		i;
	char	*buf;
	char	*temp;
	int		gnl;

	i = 10;
	while (i > 0 && (gnl = get_next_line(0, &buf)) > 0)
	{
		temp = info->header;
		info->header = ft_strjoin(temp, buf);
		ft_strdel(&temp);
		ft_strdel(&buf);
	}
	return (gnl);
}

int		main(int argc, char **argv)
{
	char	*buf;
	int		time;
	t_bon	info;
	int		gnl;

	if (argc > 1)
		check_flag(&(info.flag[0]), &argv, &argc);
	info.header = ft_strdup("");
	if ((gnl = read_header(&info)) != 1)
		return (gnl);
	while (gnl)
	{
		gnl = read_input(&info);
		time = 10000000 * info.flag[1];
		while (time > 0)
			time--;
		ft_putstr("\033[2J");
		ft_putstr("\033[0;0f");
	}
	return (0);
}
