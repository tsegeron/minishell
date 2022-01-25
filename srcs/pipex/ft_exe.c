/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseastar <mseastar@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:29:11 by mseastar          #+#    #+#             */
/*   Updated: 2022/01/22 16:22:44 by mseastar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../hdrs/minishell.h"

int	ft_exe(char **split_path, char **split_cmd, char **envp)
{
	int		i;
	char	*cmd;

	i = -1;
	while (split_path[++i])
	{
		cmd = ft_strjoin(split_path[i], split_cmd[0]);
		if (!cmd)
			return ((int)(write(2, "Error joined path to cmd.\n", 27)));
		if (execve(cmd, split_cmd, envp) < 0)
		{
			free(cmd);
			continue ;
		}
	}
	if (!split_path[i])
		exit((int)write(2, "Command was not found.\n", 23));
	return (0);
}
