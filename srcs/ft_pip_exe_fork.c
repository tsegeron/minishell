#include "../hdrs/minishell.h"


static int	ft_check_argv(void)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = -1;
	while (g_v.av[++i])
	{
		if (ft_strchr_count(g_v.av[i], '\\'))
			return (1);
		count += ft_strchr_count(g_v.av[i], '"');
	}
	if (count % 2)
		return (1);
	return (0);
}

void	ft_pip_exe_fork(void)
{
	if (ft_check_argv())
	{
		printf("Error one more \\ or \" is not both\n");
		return;
	}
	printf("OK\n");
}