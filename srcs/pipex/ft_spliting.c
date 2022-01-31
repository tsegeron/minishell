/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spliting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseastar <mseastar@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:22:53 by mseastar          #+#    #+#             */
/*   Updated: 2022/01/07 14:15:34 by mseastar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

int	ft_spliting_path(char ***split)
{
	int		i;
	t_envp	*envp_step;

	g_v.path_stat = 0;
	envp_step = g_v.envp;
	while (envp_step && ft_strcmp(envp_step->var, "PATH"))
		envp_step = envp_step->next;
	if (!envp_step)
	{
		*split = NULL;
		g_v.path_stat = 1;
		return (0);
	}
	*split = ft_split(envp_step->val, ':');
	i = -1;
	while ((*split)[++i])
	{
		(*split)[i] = ft_strjoin((*split)[i], "/");
		if (!(*split)[i])
		{
			while (i-- >= 0)
				free((*split)[i]);
			return ((int)(write(2, "Error spliting path.\n", 21)));
		}
	}
	return (0);
}

int	ft_spliting_cmd(char ***split_cmd, char *cmd)
{
	if (*split_cmd)
		ft_clear_arrray(*split_cmd);
	*split_cmd = ft_split(cmd, ' ');
	if (!(*split_cmd))
		return (1);
	free(cmd);
	return (0);
}
