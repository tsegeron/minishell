/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:09:38 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:05:25 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

int	builtins_handler(char **handle_me)
{
	if (!ft_strcmp(handle_me[0], "echo"))
		b_echo(handle_me);
	else if (!ft_strcmp(handle_me[0], "pwd"))
		b_pwd(0);
	else if (!ft_strcmp(handle_me[0], "export"))
		b_export(handle_me);
	else if (!ft_strcmp(handle_me[0], "env"))
		b_env(handle_me);
	else
		return (EXIT_FAILURE);
	if (g_v.path_stat)
		g_v.path_stat = 2;
	return (EXIT_SUCCESS);
}

int	bultins_handler_main(void)
{
	size_t	len;

	len = ft_len_array(g_v.split_cmd);
	if (!ft_strcmp(g_v.split_cmd[0], "export") && len > 1)
		b_export(g_v.split_cmd);
	else if (!ft_strcmp(g_v.split_cmd[0], "unset") && len > 1)
		b_unset(g_v.split_cmd);
	else if (!ft_strcmp(g_v.split_cmd[0], "exit"))
		b_exit(g_v.split_cmd);
	else if (!ft_strcmp(g_v.split_cmd[0], "cd"))
		b_cd(g_v.split_cmd[1]);
	else
		return (2);
	return (0);
}
