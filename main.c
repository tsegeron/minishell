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
	char *str;

	dup_envp_to_list(envp);
	g_v.ret_status = 0;
	if (ac > 1)
		return (1);
	str = malloc(10);
//	while (str)
//	{
//		free(str);
//		str = readline(BEGIN(49, 34)"eBash_$ "CLOSE);
//		if (!str)
//			return (1);
//		add_history(str);
//		ft_pip_exe_fork(str);
//	}
	while (str)
	{
		free(str);
		write(1, "eBash $", 7);
		str = get_next_line(0, 1);
		if (!str)
			return (1);
		str[ft_strlen(str) - 1] = '\0';
		ft_pip_exe_fork(str);
	}
}
