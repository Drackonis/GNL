
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 42

int	get_next_line(const int fd, char **line);

#endif
