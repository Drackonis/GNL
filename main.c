/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:58:25 by rkergast          #+#    #+#             */
/*   Updated: 2018/12/10 16:44:26 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>


int 	main(int argc, char **argv)
{
	int		fd;
	int 		ret;
	char	*line;

	line  = NULL;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		ft_putendl(line);
		printf ("LINE : |%s|\nRET : |%d|\n-------------------------NEW LINE-----------------------------", line, ret);
		getchar();
		free(line);
		line = NULL;
	}
	if (argc == 2)
		close(fd);
	return (0);
}



/*
int		main(void)
{
	int		fd;
	char	**line;
	int		tmp;
	int		i;

	i = 0;
	i = 0;
	tmp = 1;
	if ((fd = open("test42", O_RDWR | O_CREAT | O_APPEND, S_IRWXU)) == -1)
		return (1);
	if (!(line = (char**)malloc(sizeof(char*) * BUFF_SIZE)))
		return (1);
	*line = NULL;
	while (tmp == 1)
	{
		tmp = get_next_line(fd, line);
		printf("LINE : |%s|\nRET : |%d|\n-----------------------------------------------\n", *line, tmp);
		getchar();
		i++;
		free(*line);
		*line = NULL;
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}*/
