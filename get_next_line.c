/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:39:03 by rkergast          #+#    #+#             */
/*   Updated: 2018/12/10 16:52:47 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_error(int fd, char **line)
{
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	return (0);
}

static int		check_buffer(char buf[BUFF_SIZE + 1], char **tab,\
		char **line, const int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(BUFF_SIZE + 1);
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			if (tab[fd])
				tmp = tab[fd];
			tab[fd] = (ft_strcpy(ft_strnew(BUFF_SIZE - i), buf + i + 1));
			if (!*line)
				*line = ft_strncat(ft_strnew(i), buf, i);
			else
				*line = ft_strjoin(*line, ft_strncat(ft_strnew(i + 1), buf, i));
			if (tmp)
				free(tmp);
			return (1);
		}
		i++;
	}
	return (0);
}

static	int		get_buffer(char **tab, const int fd, char buf[BUFF_SIZE + 1])
{
	int			ret;

	ret = 1;
	if (tab[fd] != NULL)
	{
		ft_strncpy(buf, tab[fd], BUFF_SIZE);
		free(tab[fd]);
		tab[fd] = NULL;
	}
	else
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret + 1] = '\0';
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char		*tab[256];
	char			buf[BUFF_SIZE + 1];
	int				ret;
	int				b;

	ret = 0;
	if (check_error(fd, line) == -1)
		return (-1);
	ret = get_buffer(tab, fd, buf);
	b = check_buffer(buf, tab, line, fd);
	if (ret != 0 && b == 1)
		return (1);
	if (ret == 0)
		return (0);
	if (!*line)
		*line = ft_strsub(buf, 0, BUFF_SIZE);
	else
		*line = ft_strjoin(*line, buf);
	get_next_line(fd, line);
	if (ret > 1)
		ret = 1;
	return (ret);
}
