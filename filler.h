/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:46:19 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/21 15:04:54 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include "libft/libft.h"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define RED			"\x1b[31m"
# define RESET			"\x1b[0m"
# define CLEARE			"\033[2J"
# define TO_BEGIN		"\033[0;0f"
# define INT_MAX	2147483647

typedef struct		s_fil
{
	int				p_n;
	int				h_map;
	int				w_map;
	int				h_tokens;
	int				w_tokens;
	int				h_m_tok;
	int				w_m_tok;
	char			**map;
	t_list			*tokens;
	t_list			*hos_cor;
	int				*all_target;
	int				win;
}					t_fil;

typedef	struct		s_bon
{
	int				flag[2];
	int				p_n;
	char			*header;
	char			*o;
	int				map_size;
	int				piece_size;
}					t_bon;

int					read_map(t_fil *info);
void				find_coordinates(t_fil *info);
void				find_hostile(t_fil *info, char c);
int					read_tokens(t_fil *info);
t_list				*write_coordinates(int h, int w, char c, int *win);
int					comp_char(char c, int p_nbr);
void				print_coordinates(int h, int w);
void				find_place(t_fil *info);
void				read_sizes(int *h_size, int *w_size, int from, char *buf);
void				write_into_info(t_fil *info, t_list *hos, int h, int w);
void				check_flag(int *flag, char ***argv, int *argc);
int					read_input(t_bon *info);
int					read_player_nbr(void);
void				lst_free(t_list **lst);
void				free_arr(char ***arr, int size);

#endif
