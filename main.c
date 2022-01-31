/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:49:03 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/31 00:11:46 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*str;

	if (ac != 1)
	{
		ft_putstr_fd("eBash: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (127);
	}
	dup_envp_to_list(envp);
	g_v.ret_status = 0;
	while (1)
	{
		handle_signals();
		wait(NULL);
		str = readline("eBash_$ ");
		if (!str)
			return (eof_exit());
		if (str[0])
			add_history(str);
		ft_pip_exe_fork(str);
		close(g_v.fd[0]);
		close(g_v.fd_out);
		free(str);
	}
}
