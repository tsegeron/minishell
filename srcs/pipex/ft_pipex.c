/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseastar <mseastar@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:23:09 by mseastar          #+#    #+#             */
/*   Updated: 2022/01/13 19:03:29 by mseastar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

static void	ft_wait_all(int num)
{
	while (--num > 0)
		wait(NULL);
}

char	*ft_str_for_cmd(char **array, int *i)
{
	char	*str_util;
	int		pid;

	str_util = NULL;
	while (array[*i] && ft_strcmp(array[*i], "|"))
	{
		if (!ft_strncmp("./", array[*i], 2))
		{
			pid = fork();
			if (!pid)
				if (execve(array[*i], array + *i + 1, g_v.envp_for_exe) < 0)
					exit(1);
			wait(NULL);
			(*i) = (int)ft_len_array(array);
			return (NULL);
		}
		str_util = ft_strjoin(str_util, array[*i]);
		str_util = ft_strjoin(str_util, " ");
		(*i) += 1;
	}
	if (!ft_strcmp(array[*i], "|"))
		(*i) += 1;
	return (str_util);
}

void	ft_pipex(char **array, int *index)
{
	int		num_cmd;
	char	*str_cmd;

	num_cmd = 0;
	while (array[(*index)])
	{
		g_v.fd_save = dup(g_v.fd[0]);
		close(g_v.fd[0]);
		str_cmd = ft_str_for_cmd(array, index);
		if (!str_cmd)
			return;
		if (ft_spliting_cmd(&g_v.split_cmd, str_cmd) || \
			pipe(g_v.fd) < 0)
		{
			perror("eBash");
			exit(EXIT_FAILURE);
		}
		g_v.main_pid = fork();
		if (g_v.main_pid < 0)
		{
			perror("eBash");
			exit(EXIT_FAILURE);
		}
		if (!g_v.main_pid)
			ft_child(array, *index);
		close(g_v.fd[1]);
		num_cmd++;
	}
	close(g_v.fd[0]);
	waitpid(g_v.main_pid, &g_v.ret_status, 0);
	g_v.ret_status = WEXITSTATUS(g_v.ret_status);
	ft_wait_all(num_cmd);
}
