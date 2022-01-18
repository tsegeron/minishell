/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:13:22 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/11 13:47:00 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

t_list	*ft_lstnew(char *str)
{
	t_list	*list;

	list = (t_list *) ft_calloc(1, sizeof(t_list));
	if (list)
	{
		list->str = str;
		list->next = NULL;
	}
	return (list);
}
