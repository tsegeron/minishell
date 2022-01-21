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
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (EXIT_FAILURE);
	}
	envp_head = g_v.envp;
	while (envp_head)
	{
		ft_putstr_fd(envp_head->var, 1);
		write(1, "=", 1);
		ft_putendl_fd(envp_head->val, 1);
		envp_head = envp_head->next;
	}
	return (EXIT_SUCCESS);
}
