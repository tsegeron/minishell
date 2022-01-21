/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:09:38 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 18:09:38 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

int	builtins_handler(char **handle_me)
{
	if (!ft_strcmp(handle_me[0], "echo"))
		b_echo(handle_me);
	else if (!ft_strcmp(handle_me[0], "cd"))
		b_cd(handle_me[1]);
	else if (!ft_strcmp(handle_me[0], "pwd"))
		b_pwd(0);
	else if (!ft_strcmp(handle_me[0], "export"))
		b_export(handle_me);
	else if (!ft_strcmp(handle_me[0], "unset"))
		b_unset(handle_me);
	else if (!ft_strcmp(handle_me[0], "exit"))
		b_exit(handle_me);
	else if (!ft_strcmp(handle_me[0], "env"))
		b_env(handle_me);
	return (EXIT_SUCCESS);
}
