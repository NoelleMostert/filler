/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 09:48:42 by nmostert          #+#    #+#             */
/*   Updated: 2018/06/04 10:03:38 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				str[i] = f(i, str[i]);
				i++;
			}
			return (str);
		}
	}
	return (0);
}
