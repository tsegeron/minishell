/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:47:28 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:05:25 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

static void	ft_lst_del_elem(char *del_me)
{
	t_envp	*envp_ptr;
	t_envp	*prev;

	envp_ptr = g_v.envp;
	prev = NULL;
	if (!envp_ptr->next)
	{
		free(envp_ptr->var);
		free(envp_ptr->val);
		free(envp_ptr);
		return ;
	}
	while (ft_strcmp(del_me, envp_ptr->var))
	{
		prev = envp_ptr;
		envp_ptr = envp_ptr->next;
	}
	free(envp_ptr->var);
	free(envp_ptr->val);
	if (!prev)
		g_v.envp = g_v.envp->next;
	else
		prev->next = envp_ptr->next;
	free(envp_ptr);
}

static int	check_line(char *check_me)
{
	size_t	i;

	i = 0;
	if (ft_isalpha(check_me[i]) != 1)
		return (EXIT_FAILURE);
	i++;
	while (check_me[i])
	{
		if (!ft_isalpha(check_me[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	print_error(char *str)
{
	ft_putstr_fd("eBash: unset: `", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("': not a valid identifier", 2);
}

int	b_unset(char **av)
{
	t_envp	*envp_ptr;
	size_t	i;

//	for (int j = 0; av[j]; j++)
//		printf("%s\n", av[j]);
	i = 0;
	while (av[++i])
	{
		envp_ptr = g_v.envp;
		if (!envp_ptr)
			return (EXIT_FAILURE);
		if (check_line(av[i]))
		{
			print_error(av[i]);
			continue ;
		}
		while (envp_ptr)
		{
			if (!ft_strcmp(av[i], envp_ptr->var))
			{
				ft_lst_del_elem(envp_ptr->var);
				continue ;
			}
			envp_ptr = envp_ptr->next;
		}
	}
	return (EXIT_SUCCESS);
}
