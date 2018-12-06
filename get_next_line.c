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

static int		check_error(int fd, char **tab, char **line)
{
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (!tab)
	{
		if(!(tab = (char**)malloc(sizeof(char*) * fd)))
			return (-1);
	}
	return (0);
}

/*static char	**read_line(char **tab, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int	ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tab[fd] = ft_strjoin(tab[fd], buf);
	}
	return (tab);
}*/

int		get_next_line(const int fd, char **line)
{
	static char	**tab;
	char	buf[BUFF_SIZE];
	int	ret;
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf ("print test : \n"); 
	if (check_error(fd, tab, line) == -1)
		return (-1);
	printf ("print test : 1\n"); 
/*
	 * if (tab[fd])
		ft_strcpy(*line, tab[fd]);
	tab = read_line(tab, fd);
	i = 0;
	if (tab[fd][i])
	{
		while (tab[fd][i] != '\n' && tab[fd][i])
		       i++;
		if (i == 0)
			*line = ft_strdup("");
		else
		{
			*line = ft_strsub(tab[fd], 0, i);
			tab[fd] += i + 1;
		}
		return (1);
	}
	else
		*line = ft_strdup("");
	return (0);
*/
	if (tab)
	{
		printf ("print test : 2.A\n"); 
		*buf = (int)ft_strsub(tab[fd], 0, BUFF_SIZE);
	}
	else
	{
		printf ("print test : 2.B\n"); 
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret + 1] = '\0';
	}
	printf ("print test : 3. buf : %s\n", buf); 
	while (buf[i])
	{
		printf ("print test : 3.A\n"); 
		if (buf[i] == '\n')
		{
			printf ("print test : 3.C.1\n"); 
			//*line = ft_strsub(buf, 0, i);
			printf ("print test : 3.C.2\n"); 
			//tab[fd] = ft_strsub(buf, i, BUFF_SIZE);
			printf ("print test : 3.C.3\n"); 
			j++;
			break;
		}
		printf ("print test : 3.B.%d\n", i); 
		i++;
	}
	printf ("print test : 4.%s\n", *line); 
	/*if (buf[i] == '\0')
		*line = ft_strsub(buf, 0, i);*/
	if (!*line)
		*line = ft_strsub(buf, 0, BUFF_SIZE);
	else if (j < 1)
	{
		*line = ft_strjoin(*line, buf);
	}
	printf ("print test : 4.A\n"); 
	if (j > 0)
	{
		printf ("print test : 4.D\n"); 
	}
	if (j < 1)
	{
		printf ("print test : 4.B.%d\n", i); 
		//tab[fd] = tab[fd] + i;
		printf ("print test : 4.C.%s\n", *line);	
		getchar();
		get_next_line(fd, line);

	}
	return (0);
}
