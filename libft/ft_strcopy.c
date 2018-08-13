/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:20:27 by nmostert          #+#    #+#             */
/*   Updated: 2018/06/04 13:22:45 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcopy(char *ret, const char *s, int start, int end)
{
	int		count;

	count = 0;
	while (start <= end)
	{
		ret[count] = s[start];
		count++;
		start++;
	}
	ret[count] = '\0';
	return (ret);
}
