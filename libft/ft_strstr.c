/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:42:55 by nmostert          #+#    #+#             */
/*   Updated: 2018/06/01 14:59:48 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int str;

	str = 0;
	if (!needle[str])
		return ((char *)haystack);
	while (haystack[str])
	{
		str = 0;
		while (haystack[str] == needle[str])
		{
			if (needle[str + 1] == '\0')
				return ((char *)haystack);
			str++;
		}
		haystack++;
	}
	return (NULL);
}
