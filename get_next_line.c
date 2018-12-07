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

static int		check_error(int fd, char **line)
{
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*tab[256];
	char	buf[BUFF_SIZE];
	char	*tmp;
	int	ret;
	int	i;
	int	j;

	//INITIALIZE
	i = 0;
	j = 0;
	tmp = ft_strnew(BUFF_SIZE + 1);

	//ERROR
	if (check_error(fd, line) == -1)
		return (-1);

	//TAB != NULL ADD TAB -> LINE 
	printf ("BEGIN\n");
	if (tab[fd])
		printf ("TAB EXIST : |%s\n", tab[fd]);
	if (tab[fd] != NULL)
	{
		*line = ft_strdup(tab[fd]);
		free(tab[fd]);
		tab[fd] = NULL;
		printf ("ADD PREVIOUS TAB -> line : |%s\n", *line);
	}
	//FILL BUF WITH FD
	printf ("BUF : |%s\n", buf);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret + 1] = '\0';
	printf ("FILL BUF ; |%s\n", buf);
	printf ("ALONG BUFFER\n");
	while (buf[i])
	{
		printf ("|%d->%c|\n", i, buf[i]);
		//END OF LINE IN BUFFER
		if (buf[i] == '\n')
		{
			printf ("END OF BUF : |%s\n", buf + i);
			//FILL TAB WITH REST OF BUFFER
			if (tab[fd])
				tmp = tab[fd];
			tab[fd] = (ft_strcpy(ft_strnew(BUFF_SIZE - i), buf + i + 1));
			printf ("FILL TAB[FD] with end of buf : |%s\n", tab[fd]); 
			*line = ft_strncat(*line, buf, i);
			if (tmp)
				free(tmp);
			printf ("FILL LINE whith start of buf : |%s\n", *line); 
			j++;
			break;
		}
		i++;
	}
	if (!*line)
	{
		*line = ft_strsub(buf, 0, BUFF_SIZE);
		printf ("Create line : |%s\n", *line);
	}
	else if (j < 1)
	{
		printf ("Add buf : |%s| in line : |%s|\n", buf, *line);
		*line = ft_strjoin(*line, buf);
		printf ("ADDED : LINE : |%s\n", *line);
	}
	if (j > 1)
	{
		printf ("Where is this ?\n"); 
	}
	if (j < 1)
	{
		printf("BOUCLE GNL\n");
		getchar();
		get_next_line(fd, line);

	}
	return (0);
}
