/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:22:25 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/22 17:00:08 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_getplayer(t_map *f)
{
	get_next_line(f->fd, &(f->line));
	if (f->line[10] == 1)
	{
		f->player.us = 'X';
		f->player.them = 'O';
	}
	else
	{
		f->player.us = 'O';
		f->player.them = 'X';
	}
}

void	ft_getmapsize(t_map *f)
{
	int i;

	get_next_line(f->fd, &(f->line));
	i = 0;
	if (f->turn == 0)
	{
		f->board.heightb = ft_atoi(ft_strchr(f->line, ' '));
		f->board.lengthb = ft_atoi(ft_strrchr(f->line, ' '));
		f->board.board = (char**)malloc(sizeof(char *) * f->board.
				heightb + 1);
	}
	get_next_line(f->fd, &(f->line));
	while (i < f->board.heightb)
	{
		get_next_line(f->fd, &(f->line));
		f->board.board[i] = ft_strdup(4 + f->line);
		i++;
	}
}

void	ft_getpiece(t_map *f)
{
	int i;

	get_next_line(f->fd, &(f->line));
	i = 0;
	f->piece.heightp = ft_atoi(ft_strsplit(f->line, ' ')[1]);
	f->piece.lengthp = ft_atoi(ft_strsplit(f->line, ' ')[2]);
	f->piece.piece = (char**)malloc(sizeof(char *) * f->piece.heightp + 1);
	while (i < f->piece.heightp)
	{
		get_next_line(f->fd, &(f->line));
		f->piece.piece[i] = ft_strdup(f->line);
		i++;
	}
	f->piece.piece[f->piece.heightp] = 0;
}

int		main(void)
{
	t_map *f;

	f = (t_map *)malloc(sizeof(t_map));
	f->turn = 0;
	f->fd = 0;
	ft_getplayer(f);
	while (1)
	{
		ft_getmapsize(f);
		ft_getpiece(f);
		trimtl(&f->piece);
		validmove(f);
		if (f->turn == -1)
			break ;
		final_place(f);
		f->turn += 1;
	}
	ft_putendl("0 0\n");
	return (0);
}
