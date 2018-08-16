/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:42:51 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/16 16:51:04 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	mapcycle(t_map *f)
{
	f->placer.mapx = 0;
	f->placer.mapy = 0;

	while (f->placer.mapx < f->board.heightb - f->trim.h)
	{
		f->placer.mapy = 0;
		while (f->placer.mapy < f->board.lengthb - f->trim.l)
		{
			if (valid(f) == 1)
			{
			//	score = rand ();  //best(f);
			//	if (f->placer.topscore < score)
			//	{
			//		f->placer.topscore = score;//best(f);
			//		f->placer.topx = f->placer.mapx;
			//		f->placer.topy = f->placer.mapy;
					printf("%i %i\n",f->placer.topx - f->trim.trim_top, f->placer.topy - f->trim.trim_right);
					return ;
			//	}
			}
			f->placer.mapy++;
		}
		f->placer.mapx++;
	}
}

int		valid(t_map *f)
{	
	int i;
	int j;
	int overlap;

	i = 0;
	j = 0;
	overlap = 0;
	while (i < f->trim.h)
	{
		j = 0;
		while (j < f->trim.l)
		{
			if (f->trim.trim[i][j] == '*')
			{
				if (f->trim.trim[f->placer.mapx + i][f->placer.mapy + j] == f->player.us || f->trim.trim[f->placer.mapx + i][f->placer.mapy + j] == f->player.us + 32)
					overlap++;
				else if (f->trim.trim[f->placer.mapx + i][f->placer.mapy + j] == f->player.them || f->trim.trim[f->placer.mapx + i][f->placer.mapy + j] == f->player.them + 32)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (overlap);
}
/*
int		best(t_map *f);

void	absdiff(t_map *f);*/
