/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastdigits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:09:29 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/13 15:59:37 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lastdigits(char *str)
{
	int i;

	i = ft_strlen(str) - 1;

	if (str[i])
	{
		while (str[i])
		{
			while (str[i] != ' ')
			{
				i--;
			}
			i += 1;
			while (str[i] >= '0' && str[i] <= '9')
			{
				write (1, &str[i], 1);
				i++;
			}
			break ;
		}
	}
	return (str);
}
