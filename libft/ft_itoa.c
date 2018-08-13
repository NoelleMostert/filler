/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:41:11 by nmostert          #+#    #+#             */
/*   Updated: 2018/06/04 11:41:14 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(long nbr)
{
	size_t	count;

	count = 0;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

static char		*ft_zero(char *numstr)
{
	numstr = (char *)malloc(2);
	numstr[0] = 48;
	numstr[1] = '\0';
	return (numstr);
}

static char		*ft_calc(long nbr, int neg, size_t x, char *numstr)
{
	if (neg)
	{
		nbr = -nbr;
		numstr[0] = 45;
	}
	numstr[x] = '\0';
	while (x > 0)
	{
		numstr[x + neg - 1] = (nbr % 10) + 48;
		x--;
		nbr = nbr / 10;
	}
	return (numstr);
}

char			*ft_itoa(int nbr)
{
	char	*numstr;
	size_t	x;
	long	temp;
	int		neg;

	neg = 0;
	temp = nbr;
	if (nbr < 0)
		neg = 1;
	x = ft_counter(temp);
	numstr = ft_strnew(x + neg);
	if (!numstr)
		return (NULL);
	if (temp == 0)
		return (ft_zero(numstr));
	return (ft_calc(temp, neg, x, numstr));
}
