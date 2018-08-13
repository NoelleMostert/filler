/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secondword.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:05:19 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/13 16:30:12 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_secondword(char *str)
{
	int		i;

	i = 0;
	if (str[i])
	{
		while (str[i])
		{
			while (str[i] == ' ' || (str[i] >= 'A' && str[i] <= 'z')) 
				i++;
			while (str[i] != ' ' && str[i] >= '0' && str[i] <= '9')
			{
				write(1, &str[i], 1);
				i++;
			}
			break;
		}
	}
	return (str);
}

/*int main(void)
{
	char *str = "Plateau 15 17:";

	ft_secondword(str);
}*/
