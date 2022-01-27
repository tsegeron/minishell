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
	while (step)
	{
		size_lst++;
		step = step->next;
	}
	g_v.envp_for_exe = ft_calloc(sizeof(char *), size_lst + 1);
	step = g_v.envp;
	i = 0;
	while (step)
	{
		g_v.envp_for_exe[i] = ft_strjoin(g_v.envp_for_exe[i], step->var);
		g_v.envp_for_exe[i] = ft_strjoin(g_v.envp_for_exe[i], "=");
		g_v.envp_for_exe[i] = ft_strjoin(g_v.envp_for_exe[i], step->val);
		i++;
		step = step->next;
	}
}

int	ft_cmd(char **array, int *i)
{
	ft_create_envp_exe();
	ft_pipex(array, i);
	unlink("here_doc");
	return (0);
}
