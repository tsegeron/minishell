/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:21:52 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:16:27 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

int	b_env(char **av)
{
	t_envp	*envp_head;

	if (!g_v.envp)
		return ((int )write(STDERR_FILENO, "(null)", 6));
	if (av[1])
	{
		ft_putstr_fd("env: ", STDERR_FILENO);
		ft_putstr_fd(av[1], STDERR_FILENO);
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
		exit(127);
	}
	envp_head = g_v.envp;
	while (envp_head)
	{
		ft_putstr_fd(envp_head->var, STDOUT_FILENO);
		write(STDOUT_FILENO, "=", 1);
		ft_putendl_fd(envp_head->val, STDOUT_FILENO);
		envp_head = envp_head->next;
	}
	exit(EXIT_SUCCESS);
}
