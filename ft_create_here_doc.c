#include "hdrs/minishell.h"

int main(int ac, char **av)
{
	char	*buffer;
	char	*str_break;
	int		fd;

	fd = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return (1);
	buffer = ft_strdup("\n\n\n\n");
	str_break = ft_strdup(av[1]);
	str_break = ft_strjoin(str_break, "\n");
	if (!buffer || !str_break)
		return (1);
	while (ft_strcmp(str_break, buffer) > 0 || ft_strcmp(str_break, buffer) < 0)
	{
		free(buffer);
		buffer = get_next_line(STDIN_FILENO, 1);
		if (!buffer)
			break ;
		if (ft_strcmp(str_break, buffer))
			write(fd, buffer, ft_strlen(buffer));
	}
	if (buffer)
		free(buffer);
	close(fd);
	return (0);
}
