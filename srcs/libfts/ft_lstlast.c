/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 23:43:34 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/11 10:20:39 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		if ((lst->next))
			return (ft_lstlast(lst->next));
	return (lst);
}
