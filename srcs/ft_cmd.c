#include "../hdrs/minishell.h"

void	ft_create_envp_exe(void)
{
	t_envp	*step;
	int		size_lst;
	int		i;

	size_lst = 0;
	step = g_v.envp;
	while(step)
	{
		size_lst++;
		step = step->next;
	}
	g_v.envp_for_exe = ft_calloc(sizeof(char *), size_lst + 1);
	step = g_v.envp;
	i = 0;
	while(step)
	{
		g_v.envp_for_exe[i] = ft_strjoin(g_v.envp_for_exe[i], step->var);
		g_v.envp_for_exe[i] = ft_strjoin(g_v.envp_for_exe[i], "=");
		g_v.envp_for_exe[i] = ft_strjoin(g_v.envp_for_exe[i], step->val);
		i++;
		step = step->next;
	}
}
int ft_cmd(char **array)
{
	int	i;
	char	*str_util;
	pid_t	pid;

	ft_create_envp_exe();
	str_util = ft_strjoin(array[0], array[1]);
	if (!str_util)
		return (1);
	i = 0;
	pid = fork();
	if (!pid)
	{
		ft_spliting_cmd(&g_v.split_cmd, array[i]);
		ft_exe(g_v.split_path, g_v.split_cmd, g_v.envp_for_exe);
		perror("exe  error:");
		exit(10);
	}
	return (0);
}