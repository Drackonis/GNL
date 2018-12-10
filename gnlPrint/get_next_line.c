/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:39:03 by rkergast          #+#    #+#             */
/*   Updated: 2018/12/10 14:24:34 by rkergast         ###   ########.fr       */
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
	char	buf[BUFF_SIZE + 1];
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
		printf ("BUF : |%s\n", buf);
		ft_strncpy(buf, tab[fd], BUFF_SIZE);
		buf[BUFF_SIZE] = '\0';
		free(tab[fd]);
		tab[fd] = NULL;
		printf ("TAB[FD] : |%s\n", tab[fd]);
		printf ("ADD PREVIOUS TAB -> buf : |%s\n", buf);
	}
	else
	{
		//FILL BUF WITH FD
		printf ("BUF : |%s\n", buf);
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret + 1] = '\0';
		printf ("FILL BUF ; |%s\n", buf);
	}
	printf ("ALONG BUFFER\n");
	while (buf[i])
	{
		if (buf[i] == '\n')
			printf ("|%d->NEW LINE|\n", i);
		else if (buf[i] < 32)
			printf ("|%d->ZERO|\n", i);
		else
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
			printf ("FILL LINE (%s) with BUF (%s) & stop at i (%d)\n", *line, buf, i);
			if (!*line)
			{
				printf ("line = strncat\n");
				*line = ft_strncat(ft_strnew(i), buf, i);
			}
			else
			{
				printf ("line = strjoin\n");
				*line = ft_strjoin(*line, ft_strncat(ft_strnew(i + 1), buf, i));
			}
			if (tmp)
				free(tmp);
			printf ("NEW LINE : |%s\n", *line); 
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
		//getchar();
		get_next_line(fd, line);
	}
	return (0);
}
