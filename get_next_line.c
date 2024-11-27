#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		grabdata[BUFFER_SIZE];
	static char	*alldata;
	static char	*remainder;
	int			nlpos;
	int			bytes_read;

	if(!fd)
		return (NULL);

	bytes_read = 0;
	nlpos = 0;
	if (remainder != NULL)
	{
		alldata = ft_strdup(remainder, 1);
		remainder = NULL;
	}
	while (1)
	{
		bytes_read = read(fd, grabdata, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		grabdata[bytes_read] = '\0';
		alldata = ft_new_strlcat(alldata, grabdata);
		while (alldata[nlpos])
		{
			if (alldata[nlpos] == '\n' || alldata[nlpos] == '\0')
				break ;
			nlpos++;
		}
	}
	if (alldata && alldata[0] != '\0')
		return (putstr_nlpos(alldata, &remainder));
	
	free(alldata);
	return (NULL);
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		int fd = open(av[1], O_RDONLY);

		char *line;
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s", line);
			free(line);
		}

		close(fd);
	}
    return (0);
}
