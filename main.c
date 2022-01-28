/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:49:03 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/25 20:23:52 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*str;

	dup_envp_to_list(envp);
	g_v.ret_status = 0;
	signal(SIGQUIT, SIG_IGN);
	if (ac != 1)
		return (1);
	str = malloc(10);
	while (1)
	{
		signal(SIGINT, my_sigint);
		if (str)
			free(str);
		wait(NULL);
		str = readline(BEGIN(49, 34)"eBash_$ "CLOSE);
		if (!str)
			return (eof_exit());
		if (str && str[0])
			add_history(str);
		ft_pip_exe_fork(str);
		close(g_v.fd[0]);
		close(g_v.fd_out);
	}
	return (EXIT_SUCCESS);
}
