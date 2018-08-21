/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:42:51 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/21 16:43:29 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	validmove(t_map *f)
{
	int x;
	int y;
	int score;

	x = -1;
	y = -1;
	score = 0;
	while (++x < (f->board.heightb - f->trim.h))
	{
		y = -1;
		while (++y < (f->board.lengthb - f->trim.l))
		{	//fprintf(stderr, "entering if valid\n");
			if (valid(f, x, y) == 1)
			{
				if (score < score_gen(x, y, f))
				{
					score = score_gen(x, y, f);
					f->placer.topx = x;
					f->placer.topy = y;
				}
			}
		}
	}
	if (score == 0)
		f->turn = -1;
}

int		valid(t_map *f, int x, int y)
{	
	int i;
	int j;
	int overlap;

	i = -1;
	j = -1;
	overlap = 0;

	while (++i < f->trim.h)
	{
		j = -1;
		while (++j < f->trim.l)
		{
			if (f->trim.trim[i][j] == '*')
			{
				if (ft_tolower(f->board.board[x + i][y + j]) == ft_tolower(f->player.us))
					overlap++;
				else if (ft_tolower(f->board.board[x + i][y + j]) == ft_tolower(f->player.them))
					return (0);
			}
		}
	}
	return (overlap);
}

void	final_place(t_map *f)
{
	int x;
	int y;

	x = f->placer.topx - f->trim.top;
	y = f->placer.topy - f->trim.right;	
	ft_putnbr(x);
	ft_putstr(" ");
	ft_putnbr(y);
	ft_putstr("\n");
}

int		absdiff(int a, int b)
{
	if (a < b)
		return (b - a);
	else
		return (a - b);
	return (0);
}

int		score_gen(int x, int y, t_map *f)
{
	int score;

	score = 0;
	if (f->board.heightb == 15)
	{
		if (f->player.us == 'X')
			score = 200 - (absdiff(x, 7) + absdiff(y, 0));
		else
			score = (f->turn < 3) ? 200 - (absdiff(x, 3) + absdiff(y, 0)) :
				200 - (absdiff(x, 7) + absdiff(y, 16));
	}
	else if (f->board.heightb == 24 && f->player.us == 'O')
		score = 200 - (absdiff(x, 12) + absdiff(y, 20));
	else if (f->board.heightb == 24 && f->player.us == 'X')
	{
		if (f->turn > 35)
			score = (absdiff(x, 12) + absdiff(y, 20));
		else if (f->turn % 2 == 0)
			score = 1000 - (absdiff(x, 19) + absdiff(y, 0));
		else
			score = 1000 - (absdiff(y, 32) + absdiff(x, 0));
	}
	else if (f->board.heightb == 100)
		score = 200 - (absdiff(x, 50) + absdiff(y, 49));
	return (score);
}
