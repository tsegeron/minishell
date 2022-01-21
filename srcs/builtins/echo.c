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
		ft_putstr_fd(av[i], 1);
		if (av[i + 1])
			write(1, " ", 1);
	}
	if (!j)
		write(1, "\n", 1);
	return (EXIT_SUCCESS);
}
