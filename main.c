#include "hdrs/minishell.h"

void ft_close_shell(int i)
{
	printf("%d\n", i);
	printf("YA ZAKRILSYA\n");
	exit(1);
}

int	main(int ac, char **av, char **envp)
{
	char *str;
	int i;

	g_v.storylst = NULL;
	str = malloc(10);
	ft_init_envp_gv(envp);
	while (str)
	{
		free(str);
		str = readline(BEGIN(49, 34)"eBash_$ "CLOSE);
		if (!str)
			return (1);
//		signal(SIGINT, ft_close_shell);
		add_history(str);
		g_v.av = ft_split(str, ' ');
		i = -1;
		while (g_v.av[++i])
			printf("%s\n", g_v.av[i]);
		ft_pip_exe_fork();
	}
}