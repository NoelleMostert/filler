/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:44:04 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/21 16:14:58 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

void	trimtop(t_map *f)
{
	f->trim.top_c = 0;
	f->trim.top = 0;
	while (f->trim.top < f->piece.heightp)
	{
		if (ft_containsrow(f->piece.piece[f->trim.top], '*') == 0)
		{
			f->trim.top++;
			f->trim.top_c++;
		}
		else
			break ;
	}
}

void	trimbot(t_map *f)
{
	f->trim.bottom_c = f->piece.heightp - 1;
	f->trim.bottom = 0;
	while (f->trim.bottom_c > 0)
	{
		if (ft_containsrow(f->piece.piece[f->trim.bottom_c], '*') != 1)
		{
			f->trim.bottom_c--;
			f->trim.bottom++;
		}
		else
			break ;
	}
}

void	trimleft(t_map *f)
{
	f->trim.left_c = 0;
	f->trim.left = 0;
	while (f->trim.left_c < f->piece.lengthp)
	{
		if (ft_containscol(f->piece.piece, f->trim.left_c, f->piece.heightp, '*')
				== 1)
			break ;
		else
		{
			f->trim.left_c++;
			f->trim.left++;
		}
	}
}

void	trimright(t_map *f)
{
	f->trim.right_c = f->piece.lengthp - 1;
	f->trim.right = 0;
	while (f->trim.right_c > 0)
	{
		if (ft_containscol(f->piece.piece, f->trim.right_c, f->piece.heightp,
					'*') == 1)
			break ;
		else
		{
			f->trim.right_c--;;
			f->trim.right++;
		}
	}
}

void	ft_newpiecesize(t_map *f)
{
	
	int i;

	if (f->turn > 0)
		free(f->trim.trim);
	i = 0;

	f->trim.h = f->piece.heightp - (f->trim.top + f->trim.bottom);
	f->trim.l = f->piece.lengthp - (f->trim.right + f->trim.left);
	f->trim.trim = (char **)ft_memalloc(sizeof(char *) * f->trim.h + 1);
	
	
//	fprintf(stderr, "Piece height %i\n", f->piece.heightp);
//	fprintf(stderr, "Trim top %i\n", f->trim.top);
///	fprintf(stderr, "Trim bot  %i\n", f->trim.bottom);
//	fprintf(stderr, "Piece length %i\n", f->piece.lengthp);
//	fprintf(stderr, "Trim right %i\n", f->trim.right);
//	fprintf(stderr, "Trim left %i\n", f->trim.left);
//	fprintf(stderr, "Trim Height %i\n", f->trim.h);
//	fprintf(stderr, "Trim Length %i\n", f->trim.l);

	while (i < f->trim.h)
	{
		f->trim.trim[i] = (char *)ft_strndup(f->trim.left + f->piece.piece[f->trim.top + i], f->trim.l);
		i++;
	}
	f->trim.trim[f->trim.h] = 0;
//	ft_putstr_fd("ORIGINAL\n", 2);	
//	ft_puttab_fd(f->piece.piece, 2);
//	ft_putstr_fd("TRIM\n", 2);	
//	ft_puttab_fd(f->trim.trim, 2);
}
