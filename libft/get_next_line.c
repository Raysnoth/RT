/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-cren <ele-cren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:29:53 by ele-cren          #+#    #+#             */
/*   Updated: 2017/02/23 15:58:13 by ele-cren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

int		get_next_line(const int fd, char **line)
{
	static char	*rest = NULL;
	int			ret;
	char		buff[BUFF_SIZE];
	char		*tmp;

	tmp = NULL;
	if (rest && ft_readrest(&rest, line) == 1)
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		tmp = ft_strnew(ret);
		ft_memcpy(tmp, buff, ret);
		if (ft_readbuff(tmp, &rest, line) == 1)
			return (1);
		rest = (!rest) ? tmp : ft_freestrjoin(rest, tmp, 3);
	}
	if (rest == NULL)
		return (0);
	*line = rest;
	rest = NULL;
	return ((ft_strlen(*line) == 0) ? 0 : 1);
}

int		ft_readbuff(char *buff, char **rest, char **line)
{
	char	*tmp;

	tmp = NULL;
	if ((tmp = ft_strchr(buff, '\n')))
	{
		*line = ft_strduptoc(buff, '\n');
		*line = (!*rest) ? *line : ft_freestrjoin(*rest, *line, 3);
		*rest = ft_strdup(tmp + 1);
		free(buff);
		return (1);
	}
	return (0);
}

int		ft_readrest(char **rest, char **line)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = ft_strdup(*rest);
	if ((tmp = ft_strchr(tmp2, '\n')))
	{
		free(*rest);
		*line = ft_strduptoc(tmp2, '\n');
		*rest = ft_strdup(tmp + 1);
		free(tmp2);
		return (1);
	}
	free(tmp2);
	return (0);
}
