#include "../hdrs/minishell.h"

void handler(int signum, siginfo_t * siginfo, void *code)
{
	printf("%d\n", signum);
	if (signum == SIGINT)
	{
//		printf(BEGIN(49, 34)"\n"CLOSE);
		write(1, "\b\b", 2);
		write(1, "\neBash_$ ", 9);
	}
}
void	ft_catch_sign(void)
{
	struct sigaction act, oldact;

	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGINT, &act, &oldact) < 0)
		perror("signal SIGINT");
	if (sigaction(SIGQUIT, &act, &oldact) < 0)
		perror("signal SIGQUIT");
}
