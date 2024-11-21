/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:11:03 by dimendon          #+#    #+#             */
/*   Updated: 2024/11/20 19:50:41 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char 	ret[BUFFER_SIZE];
	ssize_t			bytes_read;
	char			*line;
	int				line_len;
	int i;

	line_len = 0;
	line = malloc(BUFFER_SIZE + 1);
	if(!line)
		return (NULL);

    while ((bytes_read = read(fd, ret, BUFFER_SIZE)) > 0) {
        i = 0;  // Index for the chunk being read from static buffer
        while (i < bytes_read) {
            // If a newline is found, end the line and return
            if (ret[i] == '\n') {
                line[line_len] = '\0';
                // Move the pointer back to ret[bytes_read] (next chunk)
                // If more data remains, it will be handled in the next call.
                return line;
            }
            // If no newline, add character to line buffer
            if (line_len < BUFFER_SIZE) {
                line[line_len++] = ret[i];
            } else {
                // Reallocate to accommodate more characters
                line = realloc(line, line_len + 2);
                if (!line)
                    return NULL;
                line[line_len++] = ret[i];
            }
            i++;
        }
    }

    // If we reach here, that means no more data to read
    // Null-terminate the string and return
    if (line_len > 0) {
        line[line_len] = '\0';
        return line;
    }

    free(line);
    return NULL;
}

int main()
{
    int fd = open("text", O_RDONLY);

    char *line = get_next_line(fd);

	printf("%s\n", line);
	printf("%s\n", line);

    close(fd);
	
    return 0;
}
