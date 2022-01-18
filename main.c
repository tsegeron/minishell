#include "hdrs/minishell.h"
void ft_re()
{
	char	*str;

	str = malloc (1);
	for (int i = 0; i < 20; i++)
	{
		free(str);
		str = readline(BEGIN(49, 34)"eBash_$ "CLOSE);
		printf("%s\n", str);
		add_history(str);
	}
}
int	main(int ac, char **av, char **envp)
{
	char *str;

	ft_init_envp_gv(envp);
//	ft_re();
	str = getenv("USER");
	printf("%s\n", str);
}