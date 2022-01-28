#include "../hdrs/minishell.h"

void	my_sigint(int signum)
{
	if (signum == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(2, "  \n", 3);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_v.ret_status = 1;
	}
}

void	my_sigquit(int signum)
{
	(void)signum;
	printf("%d", SIGTERM);
}

int	eof_exit(void)
{
	write(1, "exit\n", 5);
	return (g_v.ret_status);
}