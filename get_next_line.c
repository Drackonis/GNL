/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:39:03 by rkergast          #+#    #+#             */
/*   Updated: 2018/12/05 16:57:55 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	//static char	**tab;
	int			ret;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret + 1] = '\0';
	*line = ft_strsub(buf, 0, BUFF_SIZE);
	return (0);
}
