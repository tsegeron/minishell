/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:09:56 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 18:09:56 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

static int	get_args_num(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

static int	ft_str_is_num(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] > '9' || str[i] < '0')
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	b_exit(char **av)
{
	ft_putendl_fd("exit", STDERR_FILENO);
	if (get_args_num(av) > 1 && ft_str_is_num(av[1]))
	{
		ft_putstr_fd("eBash: exit: ", STDERR_FILENO);
		ft_putstr_fd(av[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (get_args_num(av) > 2 && !ft_str_is_num(av[1]))
		ft_putendl_fd("eBash: exit: too many arguments", STDERR_FILENO);
	else if (get_args_num(av) == 2 && ft_atoi(av[1]) != 0)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
