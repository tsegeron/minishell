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

int	builtins_handler(char **handle_me, int *i)
{
	if (!ft_strcmp(handle_me[*i], "echo"))
		b_echo(handle_me);
	else if (!ft_strcmp(handle_me[*i], "cd"))
		b_cd(handle_me[++(*i)]);
	else if (!ft_strcmp(handle_me[*i], "pwd"))
		b_pwd(0);
	else if (!ft_strcmp(handle_me[*i], "export"))
		b_export(handle_me);
	else if (!ft_strcmp(handle_me[*i], "unset"))
		b_unset(handle_me);
	else if (!ft_strcmp(handle_me[*i], "exit"))
		b_exit(handle_me);
	else if (!ft_strcmp(handle_me[*i], "env"))
		b_env(handle_me);
	else
		return (EXIT_FAILURE);
	ft_str_for_cmd(handle_me, i);
	*i -= 1;
	return (EXIT_SUCCESS);
}
