/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:15:55 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/01 15:15:57 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

static int	ft_put_in_array(void)
{
	t_envp	*step;
	int		i;

	step = g_v.envp;
	i = 0;
	while (step)
	{
		g_v.envp_for_exe[i] = ft_strjoin(g_v.envp_for_exe[i], step->var);
		g_v.envp_for_exe[i] = ft_strjoin(g_v.envp_for_exe[i], "=");
		g_v.envp_for_exe[i] = ft_strjoin(g_v.envp_for_exe[i], step->val);
		if (!g_v.envp_for_exe)
		{
			ft_clear_arrray(g_v.envp_for_exe);
			return (1);
		}
		i++;
		step = step->next;
	}
	return (0);
}

int	ft_create_envp_exe(void)
{
	t_envp	*step;
	int		size_lst;

	if (g_v.envp_for_exe)
		ft_clear_arrray(g_v.envp_for_exe);
	size_lst = 0;
	step = g_v.envp;
	while (step)
	{
		size_lst++;
		step = step->next;
	}
	g_v.envp_for_exe = ft_calloc(sizeof(char *), size_lst + 1);
	if (!g_v.envp_for_exe || ft_put_in_array())
		return (1);
	return (0);
}
