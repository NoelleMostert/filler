/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:22:25 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/13 16:30:27 by nmostert         ###   ########.fr       */
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
		f->us = 'O';
		f->them = 'X';
	}
	else
	{
		f->us = 'X';
		f->them = 'O';
	}
	printf("%s\n", f->line);
	printf("%c\n", f->us);
	printf("%c\n", f->them);
	free(f->line);
}

void	ft_getmapsize(t_map *f)
{
	get_next_line(f->fd, &(f->line));

	int i;

	i = 0;
	if (f->turn == 0)
	{
		f->height = ft_atoi(ft_strsplit(f->line, ' ')[1]);
		f->length = ft_atoi(ft_strsplit(f->line, ' ')[2]);
		f->board = (char**)ft_memalloc(sizeof(char *) * f->height + 1);
	}
	printf("%s\n", f->line);
	get_next_line(f->fd, &(f->line));
	while (i < f->height)
	{
		get_next_line(f->fd, &(f->line));
		f->board[i] = ft_strdup(4 + f->line);
		i++;
	}
	printf("The height %i\n", f->height);
	printf("The length %i\n", f->length);

	f->board[f->height] = 0;
}

int main(void)
{
	t_map *f;

	f = ft_memalloc(sizeof(t_map));
	f->turn = 0;
	f->fd = open("filler.txt", O_RDONLY);
	
	ft_getplayer(f);
	ft_getmapsize(f);
	f->turn++;
	
	return (0);
}
