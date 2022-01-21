/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:02:53 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:05:25 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

static int	error_return(char *dest)
{
	ft_putstr_fd("eBash: cd: ", 2);
	ft_putstr_fd(dest, 2);
	ft_putstr_fd(": ", 2);
	perror(NULL);
	return (EXIT_FAILURE);
}

int	b_cd(char *dest)
{
	static char	*prev_dir;

	if (!dest)
		chdir(getenv("HOME"));
	else if (!ft_strcmp(dest, "-"))
	{
		if (!prev_dir)
		{
			ft_putendl_fd("eBash: cd: OLDPWD not set", 2);
			return (EXIT_FAILURE);
		}
		else
			chdir(prev_dir);
	}
	else
	{
		prev_dir = b_pwd(1);
		if (chdir(dest))
			return (error_return(dest));
	}
	return (EXIT_SUCCESS);
}