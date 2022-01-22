#include "../hdrs/minishell.h"


static int	ft_check_argv(const char *str)
{
	if (ft_strchr_count(str, '\\') || ft_strchr_count(str, '"') % 2)
		return (1);
	return (0);
}


void	ft_pip_exe_fork(char *str)
{
	int i;

	if (ft_check_argv(str))
		printf("Error one more \\ or \" is not both\n");
	else
	{
		g_v.av = ft_split_av(str);
		if (!g_v.av)
			return;
		if (ft_remove_cov(g_v.av))
			return;
//		for (int j = 0; g_v.av[j]; j++)
//			printf("%s\n", g_v.av[j]);
//		printf("OK\n");
		i = 0;
		builtins_handler(g_v.av);
		while (g_v.av[i])
			free(g_v.av[i++]);
		free(g_v.av);
	}
}
