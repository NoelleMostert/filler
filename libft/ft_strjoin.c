/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:11:16 by nmostert          #+#    #+#             */
/*   Updated: 2018/06/04 11:54:40 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		rcount;

	if (s1 && s2)
	{
		ret = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2)) + 1);
		if (!ret)
			return (NULL);
		rcount = 0;
		ft_stringput(ret, s1, rcount);
		rcount = ft_strlen(s1);
		ft_stringput(ret, s2, rcount);
		ret[ft_strlen(s1) + ft_strlen(s2) + 1] = '\0';
		return (ret);
	}
	return (NULL);
}
