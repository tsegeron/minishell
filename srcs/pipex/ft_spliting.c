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

static t_envp	*ft_ptr_on_path(void)
{
	t_envp	*envp_step;

	envp_step = g_v.envp;
	while (envp_step && ft_strcmp(envp_step->var, "PATH"))
		envp_step = envp_step->next;
	return (envp_step);
}

int	ft_spliting_path(char ***split)
{
	int		i;
	t_envp	*envp_step;

	g_v.path_stat = 0;
	envp_step = ft_ptr_on_path();
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
