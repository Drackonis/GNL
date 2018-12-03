
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFF_SIZE 4096

void	ft_putstr_fd(int fd, char *str)
{
	int	i;
	char	n;

	i = 0;
	n = '\n';
	while (str[i])
		i++;
	write (fd, str, i);
	write (fd, &n, 1);
}	

int	main(void)
{
	int	fd;
	int	ret;
	char	buf[BUFF_SIZE + 1];

	if ((fd = open("test42~", O_RDWR | O_CREAT | O_APPEND, S_IRWXU)) == -1)
		return (1);
	printf ("%d\n", fd);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	/*ft_putstr_fd(fd, "Hello world !");*/
	ft_putstr_fd(1, buf);
	if (close(fd) == -1)
		return (1);
	return (0);
}
