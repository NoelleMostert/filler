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

int			calc_x_trim(t_piece *p, int i)
{
	int j;
	int flag;

	flag = p->lengthp;
	while (i < p->heightp)
	{
		j = 0;
		while (j < p->lengthp)
		{
			if (p->piece[i][j] == '*')
			{
				if (j < flag)
					flag = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (flag);
}

void	trimtl(t_piece *p)
{
	int		i;
	char	**new_piece;

	i = 0;
	while (i < p->heightp)
	{
		if (ft_strchr(p->piece[i], '*') != NULL)
			break ;
		i++;
	}
	p->height_trim = i;
	new_piece = (char **)malloc(sizeof(char *) * p->heightp - i);
	p->length_trim = calc_x_trim(p, i);
	i = 0;
	while (i < p->heightp - p->height_trim)
	{
		new_piece[i] = ft_strdup(p->piece[i + p->height_trim] + p->length_trim);
		i++;
	}
	p->piece = new_piece;
	p->heightp -= p->height_trim;
	p->lengthp -= p->length_trim;
	trimbot(p);
	trimright(p);
	//return (1);
}

void	trimtop(t_map *f)
{
	f->trim.top_c = 0;
	f->trim.top = 0;
	/*while (f->trim.top < f->piece.heightp)
	{
		if (ft_containsrow(f->piece.piece[f->trim.top], '*') == 0)
		{
			f->trim.top++;
			f->trim.top_c++;
		}
		else
			break ;
	}
	*/
}

void	trimbot(t_piece *p)
{
	/*f->trim.bottom_c = f->piece.heightp - 1;
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
	*/
	int		j;

	j = p->heightp - 1;
	while (j > 0)
	{
		if (ft_strchr(p->piece[j], '*') != NULL)
			break;
		j--;
	}
	p->heightp = j + 1;
}

void	trimleft(t_map *f)
{
	f->trim.left_c = 0;
	f->trim.left = 0;
	/*while (f->trim.left_c < f->piece.lengthp)
	{
		if (ft_containscol(f->piece.piece, f->trim.left_c, f->piece.heightp, '*')
				== 1)
			break ;
		else
		{
			f->trim.left_c++;
			f->trim.left++;
		}
	}*/
}

void	trimright(t_piece *p)
{
	int	i;

	i = p->lengthp - 1;
	while (i > 0)
	{
		if (ft_containscol(p->piece, i, p->heightp, '*') == 1)
			break ;
		i--;
	}
	p->lengthp = i + 1;
	/*while (f->trim.right_c > 0)
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
	*/
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
	while (i < f->trim.h)
	{
		f->trim.trim[i] = (char *)ft_strndup(f->trim.left + f->piece.piece[f->trim.top + i], f->trim.l);
		i++;
	}
	f->trim.trim[f->trim.h] = 0;
}
