/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:11:55 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/18 18:37:53 by mseastar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

int	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*prev_ptr;

	if (!lst)
		return (0);
	tmp = *lst;
	while (tmp != NULL)
	{
		prev_ptr = tmp->next;
		free(tmp);
		tmp = prev_ptr;
	}
	*lst = NULL;
	return (1);
}
