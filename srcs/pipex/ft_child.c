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

void	ft_child(char **array, int i)
{
	if (dup2(g_v.fd_save, STDIN_FILENO) < 0)
		exit(EXIT_FAILURE);
	close(g_v.fd_save);
	if (i == (int)ft_len_array(array))
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
	if (ft_exe(g_v.split_path, g_v.split_cmd, g_v.envp_for_exe))
		exit(EXIT_FAILURE);
}
