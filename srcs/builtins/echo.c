/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:17:29 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:05:25 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

int	b_echo(char **av)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!ft_strcmp(av[1], "-n"))
	{
		i++;
		j++;
	}
	while (av[++i])
	{
		ft_putstr_fd(av[i], STDOUT_FILENO);
		if (av[i + 1])
			write(g_v.fd_out, " ", 1);
	}
	if (!j)
		write(STDOUT_FILENO, "\n", 1);
	g_v.ret_status = 0;
	return (EXIT_SUCCESS);
}
