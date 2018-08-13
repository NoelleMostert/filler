/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:28:47 by nmostert          #+#    #+#             */
/*   Updated: 2018/05/30 11:09:56 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char a;
	long number;

	number = n;
	if (n < 0)
	{
		number = number * -1;
		ft_putchar_fd('-', fd);
	}
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	a = 48 + (number % 10);
	ft_putchar_fd(a, fd);
}
