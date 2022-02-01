/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:11:15 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:05:25 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

static char	*get_new_shlvl(char *str)
{
	char	*tmp;
	int		lvl;

	tmp = get_envp_val_name(str, 0);
	lvl = ft_atoi(tmp) + 1;
	free(tmp);
	tmp = ft_itoa_uns(lvl);
	return (tmp);
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_')
		return (1);
	else if (c >= '0' && c <= '9')
		return (2);
	return (0);
}

t_envp	*ft_lstlast_envp(t_envp *lst)
{
	if (lst)
		if ((lst->next))
			return (ft_lstlast_envp(lst->next));
	return (lst);
}

t_envp	*ft_lstnew_envp(char *str)
{
	t_envp	*list;

	list = (t_envp *) ft_calloc(1, sizeof(t_envp));
	if (list)
	{
		list->var = get_envp_val_name(str, 1);
		if (!ft_strcmp(list->var, "SHLVL"))
			list->val = get_new_shlvl(str);
		else
			list->val = get_envp_val_name(str, 0);
		list->next = NULL;
	}
	return (list);
}

void	ft_lstadd_back_envp(t_envp **lst, t_envp *new)
{
	t_envp	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast_envp(*lst);
	tmp->next = new;
}
