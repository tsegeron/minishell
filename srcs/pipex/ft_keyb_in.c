#include "../../hdrs/minishell.h"

int	ft_keyb_in(int fd, char *str)
{
	char **str2;
	pid_t pid;
	int status;

	str2 = ft_calloc(3, sizeof(char *));
	str2[0] = ft_strdup("./a.out");
	str2[1] = str;
	pid = fork();
	if (!pid)
		execve(str2[0], str2, g_v.envp_for_exe);
	wait(&status);
	printf("%d\n", WEXITSTATUS(status));
	return (0);
}
