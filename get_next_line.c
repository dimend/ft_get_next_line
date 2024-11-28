#include "get_next_line.h"

static size_t findnl(char *alldata)
{
	size_t nl;

	nl = 0;

		while (alldata[nl])
		{
			if (alldata[nl] == '\n' || alldata[nl] == '\0')
				return(1);
			nl++;
		}
	return (0);
}
char	*get_next_line(int fd)
{
	char		grabdata[BUFFER_SIZE];
	static char	*alldata;
	static char	*remainder;
	size_t			bytes_read;

	if(!fd || fd < 0)
		return (NULL);

	bytes_read = 0;
	if (remainder != NULL)
		alldata = ft_strdup(remainder, '\0', 1);
	while (1)
	{
		bytes_read = read(fd, grabdata, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		grabdata[bytes_read] = '\0';
		alldata = ft_new_strlcat(alldata, grabdata);
		if (findnl(alldata))
			break;
	}
	if (alldata && alldata[0] != '\0')
		return (putstr_nlpos(alldata, &remainder));
	free(alldata);
	return (NULL);
}

/* int main(int ac, char *av[])
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
} */
