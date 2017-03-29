/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:36:07 by dburtnja          #+#    #+#             */
/*   Updated: 2017/03/21 15:07:21 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_string(t_fil *info, char **str)
{
	t_list	*p;
	int		w;
	int		h;

	h = 0;
	info->tokens = NULL;
	while (info->h_tokens > h)
	{
		w = 0;
		while (info->w_tokens > w)
		{
			if (str[h][w] != '.')
			{
				p = write_coordinates(h - info->h_m_tok, w - info->w_m_tok,
						0, NULL);
				ft_lstadd_back(&(info->tokens), p);
			}
			w++;
		}
		ft_strdel(&(str[h]));
		h++;
	}
}

void	find_size(char **tok, t_fil *info)
{
	int	h;
	int f;
	int	w;

	f = 0;
	h = 0;
	while (h < info->h_tokens)
	{
		w = 0;
		while (w < info->w_tokens)
		{
			if (tok[h][w] == '*' && f == 0)
			{
				f = 1;
				info->h_m_tok = h;
			}
			if (tok[h][w] == '*' && w < info->w_m_tok)
				info->w_m_tok = w;
			w++;
		}
		h++;
	}
}

int		read_into_array(t_fil *info)
{
	int		h;
	int		gnl;
	char	**tok;

	h = 0;
	tok = (char**)ft_memalloc(sizeof(char*) * info->h_tokens);
	while (h < info->h_tokens && (gnl = get_next_line(0, &tok[h])) > 0)
		h++;
	if (gnl == 1)
	{
		find_size(tok, info);
		read_string(info, tok);
	}
	return (gnl);
}

int		read_tokens(t_fil *info)
{
	char	*buf;
	int		gnl;

	if ((gnl = get_next_line(0, &buf)) > 0)
	{
		read_sizes(&(info->h_tokens), &(info->w_tokens), 6, buf);
		ft_strdel(&buf);
	}
	else
		return (gnl);
	if (read_into_array(info) != 1)
		return (gnl);
	return (gnl);
}
