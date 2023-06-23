#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
// #include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd)
{
	char c;
	int i = 0;
	int rd_status = 0;
	char *buffer = malloc(10000);

	if (BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
	while ((rd_status = read(fd, &c, 1)) > 0)
	{
		buffer[i++] = c;
		if (c == '\n')
			break;
	}
	if (rd_status == -1 || i == 0 || (!buffer[i - 1] && !rd_status))
	{
		return (free(buffer), NULL);
	}
	buffer[i] = '\0';
	return (buffer);

}

// int main (void)
// {
// 	int fd = open("test", O_RDONLY);
// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 		printf("%s", line);
// 	return (0);
// }