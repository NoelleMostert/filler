/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:44:04 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/22 16:44:39 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		calc_x_trim(t_piece *p, int i)
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
}

void	trimbot(t_piece *p)
{
	int		j;

	j = p->heightp - 1;
	while (j > 0)
	{
		if (ft_strchr(p->piece[j], '*') != NULL)
			break ;
		j--;
	}
	p->heightp = j + 1;
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
}
