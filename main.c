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

void	my_signal(int signum)
{
	(void)signum;
	rl_on_new_line();
	rl_redisplay();
	write(2, "  \n", 3);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int	main(int ac, char **av, char **envp)
{
	char *str;

	dup_envp_to_list(envp);

	g_v.ret_status = 0;
	if (ac > 1)
		return (1);
	str = malloc(10);
	signal(SIGINT, my_signal);
//	signal(SIGQUIT, my_signal(SIGQUIT));
	while (str)
	{
//		signal(EOF, my_signal(EOF));
		free(str);
		wait(NULL);
		str = readline(BEGIN(49, 34)"eBash_$ "CLOSE);
		if (!str)
			return (1);
		if (str[0])
			add_history(str);
		ft_pip_exe_fork(str);
		close(g_v.fd[0]);
		close(g_v.fd_out);
//		ft_clear_arrray(g_v.split_path);
//		ft_clear_arrray(g_v.envp_for_exe);
	}
	return (EXIT_SUCCESS);
}
