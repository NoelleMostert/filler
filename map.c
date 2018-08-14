/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:22:25 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/14 11:43:51 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_getplayer(t_map *f)
{
	get_next_line(f->fd, &(f->line));
	if(ft_strchr(f->line, 1))
	{
		f->player.us = 'O';
		f->player.them = 'X';
	}
	else
	{
		f->player.us = 'X';
		f->player.them = 'O';
	}
	printf("%s\n", f->line);
	printf("%c\n", f->player.us);
	printf("%c\n", f->player.them);
	free(f->line);
}

void	ft_getmapsize(t_map *f)
{
	get_next_line(f->fd, &(f->line));

	int i;

	i = 0;
	if (f->turn == 0)
	{
		f->board.heightb = ft_atoi(ft_strsplit(f->line, ' ')[1]);
		f->board.lengthb = ft_atoi(ft_strsplit(f->line, ' ')[2]);
		f->board.board = (char**)ft_memalloc(sizeof(char *) * f->board.
				heightb + 1);
	}
	printf("%s\n", f->line);
	
	get_next_line(f->fd, &(f->line));
	
	fprintf(stderr,"%s\n", f->line);
	printf("The height %i\n", f->board.heightb);
	printf("The length %i\n", f->board.lengthb);

	while (i < f->board.heightb)
	{
		get_next_line(f->fd, &(f->line));
		f->board.board[i] = ft_strdup(4 + f->line);
		i++;
	}
	ft_puttab_fd(f->board.board, 2);

	f->board.board[f->board.heightb] = 0;
}

void	ft_getpiece(t_map *f)
{
	get_next_line(f->fd, &(f->line));

	int i;

	i = 0;
	
	f->piece.heightp = ft_atoi(ft_strsplit(f->line, ' ')[1]);
	f->piece.lengthp = ft_atoi(ft_strsplit(f->line, ' ')[2]);
	f->piece.piece = (char**)ft_memalloc(sizeof(char *) * f->piece.heightp + 1);
	
	printf("%s\n", f->line);
	get_next_line(f->fd, &(f->line));
	fprintf(stderr,"%s\n", f->line);
	
	while (i < f->piece.heightp)
	{
		get_next_line(f->fd, &(f->line));
		f->piece.piece[i] = ft_strdup(f->line);
		i++;
	}
	ft_puttab_fd(f->piece.piece, 2);

	f->piece.piece[f->piece.heightp] = 0;
}

int main(void)
{
	t_map *f;

	f = ft_memalloc(sizeof(t_map));
	f->turn = 0;
	f->fd = open("filler.txt", O_RDONLY);
	
	ft_getplayer(f);
//	while (1)
//	{
		ft_getmapsize(f);
		ft_getpiece(f);
//	}

	f->turn++;
	
	return (0);
}
