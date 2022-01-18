/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:46:11 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/01 18:51:09 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

void	*ft_realloc(void **src, size_t size)
{
	void	*dst;

	if (!(*src))
		return (NULL);
	dst = malloc(size);
	if (!dst)
	{
		free (*src);
		return (NULL);
	}
	dst = ft_memmove(dst, *src, size);
	free (*src);
	*src = NULL;
	return (dst);
}
