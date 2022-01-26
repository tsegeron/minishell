/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pip_exe_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:21:09 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/25 20:28:21 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

static int	ft_check_argv(char *str)
{
	int	count1;
	int	count2;
	int	i;

	if (ft_strchr(str, '\\') || ft_strchr(str, ';'))
		return (2);
	count1 = 0;
	count2 = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' && !count1 && !count2)
			count1++;
		else if (str[i] == '\'' && count1 && !count2)
			count1--;
		else if (str[i] == '\"' && !count2 && !count1)
			count2++;
		else if (str[i] == '\"' && count2 && !count1)
			count2--;
	}
	if (count1 || count2)
		return (1);
	return (0);
}

void	ft_pip_exe_fork(char *str)
{
	int	i;

	g_v.fd[0] = dup(STDIN_FILENO);
	g_v.fd_out = dup(STDOUT_FILENO);
	if (ft_check_argv(str) == 2)
		printf("Error: undefined characters: \\ or ;\n");
	else if (ft_check_argv(str) == 1)
		printf("Error: lack of \' or \"\n");
	else
	{
//		write(1, "\b\b\b\b\b\b\b\b", 8);
		if (ft_spliting_path(&g_v.split_path))
			perror("Spliting path error");
		remove_quotes_and_split(str);
		i = 0;
		while (g_v.av[i])
		{
			if (!ft_open_fd(g_v.av, &i))
				continue;
			if (!builtins_handler(g_v.av, &i))
				i++;
			else
				ft_cmd(g_v.av, &i);
		}
		i = 0;
		while (g_v.av[i])
			free(g_v.av[i++]);
		free(g_v.av);
	}
}
