/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:28:19 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/22 17:02:34 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct	s_piece
{
	char	**piece;
	int		heightp;
	int		lengthp;
	int		height_trim;
	int		length_trim;
}				t_piece;

typedef struct	s_trim
{
	char	**trim;
	int		h;
	int		l;
	int		top;
	int		bottom;
	int		left;
	int		right;
	int		top_c;
	int		bottom_c;
	int		left_c;
	int		right_c;

}				t_trim;

typedef struct	s_board
{
	char	**board;
	int		heightb;
	int		lengthb;
}				t_board;

typedef struct	s_player
{
	int us;
	int them;
}				t_player;

typedef struct	s_place
{
	int mapx;
	int mapy;
	int topscore;
	int	topx;
	int	topy;
}				t_place;

typedef struct	s_map
{
	int			fd;
	int			linenbr;
	char		*line;
	int			enemy;
	int			place;
	int			turn;
	t_piece		piece;
	t_board		board;
	t_player	player;
	t_trim		trim;
	t_place		placer;
}				t_map;

void			trimtop(t_map *f);
void			trimtl(t_piece *p);
void			trimleft(t_map *f);
void			trimbot(t_piece *p);
void			trimright(t_piece *p);
void			ft_newpiecesize(t_map *f);
int				valid(t_map *f, int x, int y);
void			validmove(t_map *f);
void			final_place(t_map *f);
int				score_gen(int x, int y, t_map *f);
int				absdiff(int a, int b);

#endif
