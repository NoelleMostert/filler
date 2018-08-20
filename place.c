/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:42:51 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/20 15:17:10 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	mapcycle(t_map *f)
{
	//	x = 0;
	//	y = 0;
	int x = 0;
	int y = 0;
	int score;

	score = 0;
	f->placer.topscore = 0;
	fprintf(stderr, "about that while\n");
	srand(time(NULL));
	while (x < f->board.heightb - f->trim.h)
	{
		y = 0;
		while (y < f->board.lengthb - f->trim.l)
		{	
		//	fprintf(stderr, "aboit to run valid\n");
			if (valid(f, x, y) == 1)
			{
				fprintf(stderr, "this entered\n");
				score = rand () % 100 + 1;  //best(f);
				if (f->placer.topscore < score)
				{
					f->placer.topscore = score;//best(f);
					f->placer.topx = x;
					f->placer.topy = y;
					//final_place(f);
					//	return ;
				}
				fprintf(stderr, "going to exit from within\n");
			}
		//	fprintf(stderr, "ran valid \n");
			y++;
		}
		x++;
	}
	fprintf(stderr, "exiting mapcycle\n");
}

int		valid(t_map *f, int x, int y)
{	
	int i;
	int j;
	int overlap;

	i = 0;
	j = 0;
	overlap = 0;

	//fprintf(stderr, "I am validating\n");
	if (x + f->piece.lengthp >= f->board.lengthb)
		return (-1);
	if (y + f->piece.heightp >= f->board.heightb)
		return (-1);
	while (i < f->trim.h)
	{
		j = 0;
		while (j < f->trim.l)
		{
			if (f->trim.trim[i][j] == '*')
			{
				if (ft_tolower(f->trim.trim[x + i][y + j]) == ft_tolower(f->player.us))
					overlap++;
				else if (ft_tolower(f->trim.trim[x + i][y + j]) == ft_tolower(f->player.them))
					return (0);
				if (overlap > 1)
					return (overlap);
			}
			j++;
		}
		i++;
	}
	//fprintf(stderr, "I am leaving valid\n");
	return (overlap);
}

void	final_place(t_map *f)
{
	int x;
	int y;

	x = f->placer.topx - f->trim.top;
	y = f->placer.topy - f->trim.right;
	fprintf(stderr, "calling the final place\n");	
	ft_putnbr(x);
	ft_putstr(" ");
	ft_putnbr(x);
	ft_putstr("\n");
}

//   int		best(t_map *f);

int		absdiff(int a, int b)
{
	if (a < b)
		return (b - a);
	else
		return (a - b);
}
