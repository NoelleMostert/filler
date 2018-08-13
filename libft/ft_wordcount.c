/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:44:40 by nmostert          #+#    #+#             */
/*   Updated: 2018/06/04 13:24:46 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcount(const char *str, char c)
{
	int		count;
	int		words;

	count = 0;
	words = 0;
	while (str[count] == c)
		count++;
	while (str[count] != '\0')
	{
		if (str[count] == c)
		{
			while (str[count] == c)
				count++;
			words++;
		}
		count++;
	}
	return (words);
}
