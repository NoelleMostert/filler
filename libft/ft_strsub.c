/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:01:48 by nmostert          #+#    #+#             */
/*   Updated: 2018/06/04 11:39:06 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	count;

	count = 0;
	if (s)
	{
		ret = (char *)ft_memalloc(sizeof(char) * len + 1);
		if (!ret)
			return (NULL);
		while (count < len)
		{
			ret[count] = s[start];
			count++;
			start++;
		}
		ret[count] = '\0';
		return (ret);
	}
	return (NULL);
}
