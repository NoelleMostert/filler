/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:44:04 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/14 16:30:53 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

void	trimtop(t_map *f)
{
	int i;

	i = 0;


	while (i < f->piece.heightp)
	{
//		printf("line %d of piece: %s\n", i, f->piece.piece[i]);
		if(ft_strchr(f->piece.piece[i], '*') != NULL)
			break ;
		i++;
	}
	fprintf(stderr, "%d\n", i);
}

void	trimbot(t_map *f)
{
	int i;
	int j;

	j = 0;
	i = f->piece.heightp - 1;
	
	while (i > 0)
	{
//		printf("line %d of piece: %s\n", i, f->piece.piece[i]);
		if(ft_strchr(f->piece.piece[i], '*') != NULL)
			break ;
		i--;
		j++;
	}
	fprintf(stderr, "%d\n", j);
}

void	trimleft(t_map *f)
{
	int col;

	col = 0;
	while (col < f->piece.heightp)
	{
//		printf("line %d of piece: %s\n", i, f->piece.piece[i]);
		if(ft_containscol(f->piece.piece, col, f->piece.heightp - 1, '*') != 0)
			break ;
		col++;
	}
	fprintf(stderr, "%d\n", col);
}

void	trimright(t_map *f)
{
	int col;
	int right;

	right = 0;
	col  =  f->piece.lengthp - 1;
	while (col > 0)
	{
//		printf("line %d of piece: %s\n", i, f->piece.piece[i]);
		if(ft_containscol(f->piece.piece, col, f->piece.heightp - 1, '*') != 0)
			break ;
		col--;
		right++;
	}
	fprintf(stderr, "%d\n", right);
}
