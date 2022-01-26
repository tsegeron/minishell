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
	while (num-- > 0)
		wait(NULL);
}

char *ft_str_for_cmd(char **array, int *i)
{
	char	*str_util;

	str_util = NULL;
	while (array[*i] && ft_strcmp(array[*i], "|"))
	{
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
	while (array[(*index)])
	{
		g_v.fd_save = dup(g_v.fd[0]);
		close(g_v.fd[0]);
		if (ft_spliting_cmd(&g_v.split_cmd, ft_str_for_cmd(array, index)) || \
			pipe(g_v.fd) < 0)
			exit((int)write(2, "Error spliting command.\n", 24));
		g_v.main_pid = fork();
		if (g_v.main_pid < 0)
			exit((int)write(2, "Fork error.\n", 12));
		if (!g_v.main_pid)
		{
			ft_child(array, *index);
			exit(EXIT_FAILURE);
		}
		close(g_v.fd[1]);
	}
	close(g_v.fd[0]);
	ft_wait_all(ft_len_array(array) - *index);
}
