/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmostert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 12:36:55 by nmostert          #+#    #+#             */
/*   Updated: 2018/08/22 16:38:02 by nmostert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlennl(char const *c)
{
	size_t		i;

	i = 0;
	while (c[i] != '\n' && c[i] != '\0')
		i++;
	return (i);
}

static char		*ft_joinends(char *c[1], const int fd)
{
	char		*tmp;
	char		buff[BUFF_SIZE + 1];
	int			r;

	if (!(c[fd]))
		c[fd] = ft_strnew(0);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		if ((tmp = ft_strjoin(c[fd], buff)) == NULL)
			return (NULL);
		c[fd] = tmp;
		if (ft_strchr(buff, '\n') || r < BUFF_SIZE)
			break ;
	}
	return (c[fd]);
}

int				get_next_line(const int fd, char **line)
{
	static char *c[1];
	char		*tmp;
	int			r;

	if (!(line) || fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	if ((c[fd] = ft_joinends(c, fd)) == NULL)
		return (-1);
	r = ft_strlennl(c[fd]);
	if ((*line = ft_strsub(c[fd], 0, r)) == NULL)
		return (-1);
	if (c[fd][0] == '\0')
		return (0);
	if ((tmp = ft_strdup(c[fd] + r + (c[fd][r] == '\n'))) == NULL)
		return (-1);
	c[fd] = tmp;
	return (1);
}
