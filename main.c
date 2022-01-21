/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:49:03 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:18:08 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/minishell.h"

int	main(int ac, char **av, char **envp)
{
	char *str;

	str = malloc(10);
	while (str)
	{
		free(str);
		str = readline(BEGIN(49, 34)"eBash_$ "CLOSE);
		if (!str)
			return (1);
		add_history(str);
		ft_pip_exe_fork(str);
	}
}
