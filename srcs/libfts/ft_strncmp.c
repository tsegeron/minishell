/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseastar <mseastar@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:00:10 by mseastar          #+#    #+#             */
/*   Updated: 2021/10/11 11:36:37 by mseastar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../hdrs/minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*str1 && *str1 == *str2 && n - 1 > 0)
	{
		str1++;
		str2++;
		n--;
	}
	return (*str1 - *str2);
}
