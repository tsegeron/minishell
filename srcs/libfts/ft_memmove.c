/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:36:11 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/11 10:19:16 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;

	i = -1;
	if (!dst && !src)
		return (NULL);
	if ((char *)dst > (char *)src)
	{
		while (len != 0)
		{
			((char *)dst)[i + len] = ((char *)src)[i + len];
			len--;
		}
	}
	else
		while (++i < len)
			((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}
