/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:02:53 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/22 13:56:25 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

static int	error_return(char *dest)
{
	ft_putstr_fd("eBash: cd: ", 2);
	ft_putstr_fd(dest, 2);
	ft_putstr_fd(": ", 2);
	perror(NULL);
	g_v.ret_status = 1;
	return (EXIT_FAILURE);
}

static int	go_prev_dir(char **prev_dir)
{
	char	*tmp;

	if (!(*prev_dir))
	{
		ft_putendl_fd("eBash: cd: OLDPWD not set", 2);
		g_v.ret_status = 1;
		return (EXIT_FAILURE);
	}
	else
	{
		tmp = b_pwd(1);
		chdir(*prev_dir);
		free(*prev_dir);
		*prev_dir = ft_strdup(tmp);
		free(tmp);
		g_v.ret_status = 0;
	}
	return (EXIT_SUCCESS);
}

int	b_cd(char *dest)
{
	static char	*prev_dir;

	if (!dest || !ft_strcmp(dest, "~"))
	{
		if (prev_dir)
			free(prev_dir);
		prev_dir = b_pwd(1);
		chdir(getenv("HOME"));
	}
	else if (!ft_strcmp(dest, "-"))
	{
		if (go_prev_dir(&prev_dir))
			return (EXIT_FAILURE);
		b_pwd(0);
	}
	else
	{
		if (prev_dir)
			free(prev_dir);
		prev_dir = b_pwd(1);
		if (chdir(dest))
			return (error_return(dest));
	}
	g_v.ret_status = 0;
	return (EXIT_SUCCESS);
}
