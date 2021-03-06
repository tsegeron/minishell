/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pip_exe_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:21:09 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/31 00:14:50 by gernesto         ###   ########.fr       */
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
	g_v.fd[0] = dup(STDIN_FILENO);
	g_v.fd_out = dup(STDOUT_FILENO);
	if (g_v.fd[0] < 0 || g_v.fd_out < 0)
		perror("eBash");
	else if (ft_check_argv(str) == 2)
		printf("Error: undefined characters: \\ or ;\n");
	else if (ft_check_argv(str) == 1)
		printf("Error: lack of \' or \"\n");
	else
	{
		if (ft_spliting_path(&g_v.split_path))
			perror("Spliting path error");
		else
		{
			if (ft_create_envp_exe())
				return ;
			remove_quotes_and_split(str);
			if (g_v.av)
				ft_pipex(g_v.av);
			ft_clear_arrray(g_v.av);
			ft_clear_arrray(g_v.split_path);
		}
	}
}
