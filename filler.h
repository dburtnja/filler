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
	char			**tokens;
}					t_fil;

int					read_map(t_fil *info);

#endif
