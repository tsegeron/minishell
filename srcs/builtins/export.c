/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:11:45 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/23 17:38:02 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

static void	set_envp_order(void)
{
	t_envp	*cur_val;
	t_envp	*comp_val;

	if (!g_v.envp && !g_v.envp->next)
		return ;
	cur_val = g_v.envp;
	comp_val = g_v.envp->next;
	while (cur_val)
	{
		cur_val->order = 0;
		cur_val = cur_val->next;
	}
	cur_val = g_v.envp;
	while (cur_val)
	{
		while (comp_val)
		{
			if (ft_strcmp(cur_val->var, comp_val->var) > 0)
				cur_val->order++;
			comp_val = comp_val->next;
		}
		comp_val = g_v.envp;
		cur_val = cur_val->next;
	}
}

static int	print_sorted_envp(void)
{
	size_t		printed;
	t_envp		*envp_head;

	set_envp_order();
	envp_head = g_v.envp;
	printed = 0;
	while (envp_head)
	{
		if (printed == envp_head->order)
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(envp_head->var, STDOUT_FILENO);
			write(STDOUT_FILENO, "=\"", 2);
			ft_putstr_fd(envp_head->val, STDOUT_FILENO);
			write(STDOUT_FILENO, "\"\n", 2);
			printed++;
			envp_head = g_v.envp;
			continue ;
		}
		envp_head = envp_head->next;
	}
	return (EXIT_SUCCESS);
}

static int	check_line(char *check_me)
{
	size_t	i;

	i = -1;
	if (!check_me || check_me[0] == '=')
		return (EXIT_FAILURE);
	if (ft_isalpha(check_me[++i]) != 1)
		return (EXIT_FAILURE);
	while (check_me[++i] && check_me[i] != '=')
		if (!ft_isalpha(check_me[i]))
			return (EXIT_FAILURE);
	if (!ft_strchr(check_me, '='))
		return (2);
	return (EXIT_SUCCESS);
}

static void	insert_var_to_envp(char *str)
{
	t_envp	*envp_head;
	char	*var;

	envp_head = g_v.envp;
	var = get_envp_val_name(str, 1);
	while (envp_head)
	{
		if (!ft_strcmp(var, envp_head->var))
		{
			free(envp_head->val);
			envp_head->val = get_envp_val_name(str, 0);
			break ;
		}
		envp_head = envp_head->next;
	}
	if (!envp_head)
		ft_lstadd_back_envp(&g_v.envp, ft_lstnew_envp(str));
	free(var);
}

int	b_export(char **av)
{
	size_t	i;

	if (!av[1])
		return (print_sorted_envp());
	i = 0;
	while (av[++i] && !g_v.pipe_stat)
	{
		if (check_line(av[i]) == 1)
		{
			ft_putstr_fd("eBash: export: `", 2);
			ft_putstr_fd(av[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			g_v.ret_status = 1;
		}
		else if (check_line(av[i]) == 2)
			continue ;
		else
			insert_var_to_envp(av[i]);
	}
	return (EXIT_SUCCESS);
}
