/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:47:35 by nmostert          #+#    #+#             */
/*   Updated: 2018/06/04 12:11:25 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stringput(char *dest, const char *src, int dcount)
{
	int		scount;

	scount = 0;
	while (src[scount] != '\0')
	{
		dest[dcount] = src[scount];
		dcount++;
		scount++;
	}
	return (dest);
}
