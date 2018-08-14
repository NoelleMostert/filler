/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containscol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:42:30 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/14 15:48:16 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_containscol(char **s, int col, int height, int c)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (i < height)
	{
		if (s[i][col] == (char)c)
			return (1);
		else
			i++;
	}
	return (0);
}
