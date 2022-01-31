#include "../../hdrs/minishell.h"

int	ft_keyb_in(char *str)
{
	char	**str2;
	pid_t	pid;
	int		status;

	str2 = ft_calloc(3, sizeof(char *));
	str2[0] = ft_strdup("create_here_doc");
	str2[1] = str;
	pid = fork();
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	if (!pid)
		execve(str2[0], str2, g_v.envp_for_exe);
	wait(&status);
	handle_signals();
	if (WEXITSTATUS(status) != 0)
		return (1);
	return (0);
}
