#include "../hdrs/minishell.h"

static	void	*ft_start_prog(char **array, int *i)
{
	int		pid;

	pid = fork();
	if (!pid)
	{
		if (execve(array[*i], array + *i, g_v.envp_for_exe) < 0)
		{
			perror("eBash");
			exit(127);
		}
	}
	waitpid(pid, &g_v.ret_status, 0);
	g_v.ret_status = WEXITSTATUS(g_v.ret_status);
	(*i) = (int)ft_len_array(array);
	return (NULL);
}

char	*ft_str_for_cmd(char **array, int *i)
{
	char	*str_util;
	char	*str_1;
	char	*str_2;

	str_util = NULL;
	while (array[*i] && ft_strcmp(array[*i], "|"))
	{
		if (!ft_strncmp("./", array[*i], 2))
			return (ft_start_prog(array, i));
		else if (!ft_strncmp("~", array[*i], 1))
		{
			str_1 = ft_strdup(ft_strrchr(array[*i], '~') + 1);
			str_2 = ft_strdup(getenv("HOME"));
			free(array[*i]);
			array[*i] = ft_strjoin(str_2, str_1);
			if (!array[*i])
				return (NULL);
			return (ft_start_prog(array, i));
		}
		str_util = ft_strjoin(str_util, array[*i]);
		str_util = ft_strjoin(str_util, " ");
		(*i) += 1;
	}
	if (!ft_strcmp(array[*i], "|"))
		(*i) += 1;
	return (str_util);
}
