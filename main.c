/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:58:25 by rkergast          #+#    #+#             */
/*   Updated: 2018/12/05 17:05:30 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd;
	char	**line;

	if (!(line = (char**)malloc(sizeof(char*) * BUFF_SIZE)))
		return (1);
	if ((fd = open("test42~", O_RDWR | O_CREAT | O_APPEND, S_IRWXU)) == -1)
		return (1);
	get_next_line(fd, line);
	printf ("%s", line[1]);
	return (0);
}
