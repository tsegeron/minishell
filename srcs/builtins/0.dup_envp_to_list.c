/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_envp_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:23:10 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:05:25 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

char	*get_envp_val_name(char *full, int status)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = 0;
	while (full[i] != '=')
		i++;
	if (status)
	{
		ret = malloc(sizeof(char) * i + 1);
		i = -1;
		while (full[++i] != '=')
			ret[i] = full[i];
		ret[i] = '\0';
	}
	else
	{
		ret = malloc(sizeof(char) * ft_strlen(full + i + 1) + 1);
		j = 0;
		while (full[++i])
			ret[j++] = full[i];
		ret[j] = '\0';
	}
	return (ret);
}

int	dup_envp_to_list(char **envp)
{
	size_t	i;

	if (!envp)
		return (EXIT_FAILURE);
	g_v.envp = NULL;
	i = 0;
	while (envp[i])
		ft_lstadd_back_envp(&g_v.envp, ft_lstnew_envp(envp[i++]));
	return (EXIT_SUCCESS);
}
