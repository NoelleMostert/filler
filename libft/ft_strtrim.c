/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:05:56 by nmostert          #+#    #+#             */
/*   Updated: 2018/06/04 13:21:04 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		start;
	int		end;

	if (s)
	{
		start = ft_remspace(s, 0);
		end = ft_strlen(s);
		end = ft_remspace(s, end);
		if (start > end)
			return (ret = "\0");
		ret = (char *)ft_memalloc(sizeof(char) * (end - start) + 2);
		if (!ret)
			return (NULL);
		return (ft_strcopy(ret, s, start, end));
	}
	return (NULL);
}
