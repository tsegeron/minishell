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
	waitpid(g_v.main_pid, &g_v.ret_status, 0);
	g_v.ret_status = WEXITSTATUS(g_v.ret_status);
	while (--num > 0)
		wait(NULL);
}

static	void	*ft_start_prog(char **array, int *i)
{
	int		pid;

	pid = fork();
	if (!pid && execve(array[*i], array + *i + 1, g_v.envp_for_exe) < 0)
	{
		perror("eBash");
		exit(127);
	}
	waitpid(pid, &g_v.ret_status, 0);
	g_v.ret_status = WEXITSTATUS(g_v.ret_status);
	(*i) = (int)ft_len_array(array);
	return (NULL);
}

char	*ft_str_for_cmd(char **array, int *i)
{
	char	*str_util;

	str_util = NULL;
	while (array[*i] && ft_strcmp(array[*i], "|"))
	{
		if (!ft_strncmp("./", array[*i], 2))
			return (ft_start_prog(array, i));
		str_util = ft_strjoin(str_util, array[*i]);
		str_util = ft_strjoin(str_util, " ");
		(*i) += 1;
	}
	if (!ft_strcmp(array[*i], "|"))
		(*i) += 1;
	return (str_util);
}

static int	ft_piping(char **array, int *index)
{
	char	*str_cmd;

	str_cmd = ft_str_for_cmd(array, index);
	if (!str_cmd)
		return (1);
	if (ft_spliting_cmd(&g_v.split_cmd, str_cmd) || \
			pipe(g_v.fd) < 0)
	{
		perror("eBash");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	ft_pipex(char **array)
{
	int		num_cmd;
	int		index;

	index = 0;
	num_cmd = 0;
	while (array[(index)])
	{
		g_v.fd_save = dup(g_v.fd[0]);
		close(g_v.fd[0]);
		if (ft_piping(array, &index))
			return ;
		handle_signals_in_proc();
		g_v.main_pid = fork();
		if (g_v.main_pid < 0)
		{
			perror("eBash");
			exit(EXIT_FAILURE);
		}
		if (!g_v.main_pid)
			ft_child(array, &index);
		close(g_v.fd[1]);
		num_cmd++;
	}
	close(g_v.fd[0]);
	ft_wait_all(num_cmd);
}
