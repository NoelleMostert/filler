/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:28:19 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/06 15:16:26 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct	s_map
{
	int		fd;
	int		linenbr;
	char	*line;
	int		enemy;
	int		us;
	int		them;
	int		piece;
	int		place;
	int		turn
	char	**board;
	int		height;
	int		length;
}				t_map;

#endif
