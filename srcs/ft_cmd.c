#include "../hdrs/minishell.h"

void	ft_create_envp_exe(void)
{
	t_envp	*step;
	int		size_lst;
	int		i;

	if (g_v.envp_for_exe)
		ft_clear_arrray(g_v.envp_for_exe);
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

static int	ft_check_pipe(char **array, int *i)
{
	int j;

	j = (*i) - 1;
	while (array[++j])
	{
		if (!ft_strcmp(array[j], "|"))
			ft_pipex(array, i);
	}
	return (0);
}

int ft_cmd(char **array, int *i)
{
	pid_t	pid;

	ft_create_envp_exe();
	ft_check_pipe(array, i);
	ft_spliting_cmd(&g_v.split_cmd, ft_str_for_cmd(array, i));
	pid = fork();
	if (!pid)
	{
		ft_exe(g_v.split_path, g_v.split_cmd, g_v.envp_for_exe);
		perror("exe  error:");
		exit(10);
	}
	return (0);
}