//
// Created by Denys Burtnjak on 3/15/17.
//

#ifndef FILLER_H
#define FILLER_H

# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_fil
{
	int				p_n;
	int				h_map;
	int				w_map;
	int				h_tokens;
	int				w_tokens;
	char			**map;
	t_list			*tokens;
	t_list			*hos_cor;
}					t_fil;

int					read_map(t_fil *info);
void				find_coordinates(t_fil *info);
void				find_hostile(t_fil *info, char c);
int					read_tokens(t_fil *info);
t_list				*write_coordinates(int h, int w, char c);

#endif
