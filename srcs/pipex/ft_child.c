/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseastar <mseastar@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:26:14 by mseastar          #+#    #+#             */
/*   Updated: 2022/01/07 19:18:55 by mseastar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

static	void	ft_start_prog(char **array)
{
	if (execve(array[0], array, g_v.envp_for_exe) < 0)
	{
		perror("eBash 123");
		exit(127);
	}
}

static void	ft_exe_ques(char **array)
{
	char	*str_1;
	char	*str_2;

	if (!ft_strncmp("./", array[0], 2))
		ft_start_prog(array);
	else if (!ft_strncmp("~", array[0], 1))
	{
		str_1 = ft_strdup(ft_strrchr(array[0], '~') + 1);
		str_2 = ft_strdup(getenv("HOME"));
		free(array[0]);
		array[0] = ft_strjoin(str_2, str_1);
		if (!array[0])
			exit(EXIT_FAILURE);
		ft_start_prog(array);
	}
}

static void	ft_error_path(char **array)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(array[0], 2);
	ft_putendl_fd(": No such file or directory", 2);
	exit(127);
}

void	ft_child(char **array, const int *i)
{
	if (dup2(g_v.fd_save, STDIN_FILENO) < 0)
		exit(EXIT_FAILURE);
	close(g_v.fd_save);
	if (*i == (int)ft_len_array(array))
	{
		if (dup2(g_v.fd_out, STDOUT_FILENO) < 0)
			exit(EXIT_FAILURE);
		close(g_v.fd_out);
	}
	else
	{
		if (dup2(g_v.fd[1], STDOUT_FILENO) < 0)
			exit(EXIT_FAILURE);
		close(g_v.fd[1]);
	}
	if (!builtins_handler(g_v.split_cmd))
		exit(EXIT_SUCCESS);
	ft_exe_ques(g_v.split_cmd);
	if (g_v.path_stat == 2)
		exit(EXIT_SUCCESS);
	else if (g_v.path_stat == 1)
		ft_error_path(g_v.split_cmd);
	ft_exe(g_v.split_path, g_v.split_cmd, g_v.envp_for_exe);
	exit(EXIT_FAILURE);
}
