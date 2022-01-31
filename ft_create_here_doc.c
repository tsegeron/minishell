#include "hdrs/minishell.h"

static void	my_sigquit1(int signum)
{
	(void)signum;
	printf("Quit: %d\n", signum);
	exit(0);
}

static void	my_sigint_proc1(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		exit(0);
	}
}

static void	handle_signals_in_proc1(void)
{
	signal(SIGQUIT, my_sigquit1);
	signal(SIGINT, my_sigint_proc1);
}

int main(int ac, char **av)
{
	char	*buffer;
	char	*str_break;
	int		fd;

	(void) ac;
	handle_signals_in_proc1();
	fd = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		return (1);
	buffer = ft_strdup("\t");
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
