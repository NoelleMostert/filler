/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:28:19 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/14 12:58:33 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct s_piece
{
	char **piece;
	int heightp;
	int lengthp;
}				t_piece;

typedef struct	s_board
{
	char **board;
	int heightb;
	int lengthb;
}				t_board;

typedef struct	s_player
{
	int us;
	int them;
}				t_player;

typedef struct	s_map
{
	int		fd;
	int		linenbr;
	char	*line;
	int		enemy;
	t_piece piece;
	t_board board;
	t_player player;
	int		place;
	int		turn;
}				t_map;

#endif
