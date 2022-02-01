/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_for_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:15:22 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/01 15:15:23 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

static int	ft_count_char_ptr(char **array, int *i)
{
	int	num;

	num = *i;
	while (array[*i] && ft_strcmp(array[*i], "|"))
		(*i)++;
	g_v.split_cmd = ft_calloc(*i - num + 1, sizeof(char *));
	return (num);
}

int	ft_str_for_cmd(char **array, int *i)
{
	int	save;
	int	j;

	if (g_v.split_cmd)
		ft_clear_arrray(g_v.split_cmd);
	save = ft_count_char_ptr(array, i);
	if (!g_v.split_cmd)
		return (1);
	j = 0;
	while (save < *i)
	{
		g_v.split_cmd[j] = ft_strdup(array[save++]);
		if (!g_v.split_cmd[j])
		{
			ft_clear_arrray(g_v.split_cmd);
			return (1);
		}
		j++;
	}
	if (!ft_strcmp(array[*i], "|"))
	{
		(*i) += 1;
		g_v.pipe_stat = 1;
	}
	return (0);
}
