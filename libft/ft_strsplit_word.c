/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 17:25:43 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/22 16:32:24 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsplit_word(char const *s, char c, size_t num)
{
	char		*arr;
	size_t		i;
	size_t		j;
	size_t		k;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = i;
		while (s[i] != c && i < (size_t)ft_strlen(s))
			i++;
		if (k + 1 == num)
			arr = (char *)ft_strsub(s, j, (i - j));
		k++;
	}
	return (arr);
}
