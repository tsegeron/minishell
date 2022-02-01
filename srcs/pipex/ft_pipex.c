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
	if (waitpid(g_v.main_pid, &g_v.ret_status, 0) > -1)
		g_v.ret_status = WEXITSTATUS(g_v.ret_status);
	while (--num > 0)
		wait(NULL);
}

static int	ft_piping(char **array, int *index)
{
	if (ft_str_for_cmd(array, index))
		return (EXIT_FAILURE);
	if (pipe(g_v.fd) < 0)
	{
		perror("eBash");
		return (EXIT_FAILURE);
	}
	return (0);
}

static int	ft_forking(char **array, int *i)
{
	handle_signals_in_proc();
	g_v.main_pid = fork();
	if (g_v.main_pid < 0)
	{
		perror("eBash");
		return (1);
	}
	if (!g_v.main_pid)
		ft_child(array, i);
	return (0);
}

void	ft_pipex(char **array)
{
	int	num_cmd;
	int	index;

	index = 0;
	num_cmd = 0;
	while (array[(index)])
	{
		g_v.fd_save = dup(g_v.fd[0]);
		close(g_v.fd[0]);
		if (ft_piping(array, &index))
			return ;
		if (bultins_handler_main() == EXIT_SUCCESS)
		{
			close(g_v.fd_save);
			continue ;
		}
		if (ft_forking(array, &index))
			return ;
		close(g_v.fd[1]);
		num_cmd++;
	}
	close(g_v.fd[0]);
	ft_wait_all(num_cmd);
}
