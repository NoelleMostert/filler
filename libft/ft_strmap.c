/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 09:47:32 by nmostert          #+#    #+#             */
/*   Updated: 2018/06/04 10:05:57 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	if (s)
	{
		str = ft_strdup(s);
		if (str)
		{
			while (str[i])
			{
				str[i] = f(str[i]);
				i++;
			}
			return (str);
		}
	}
	return (0);
}
