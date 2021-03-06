/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:50:45 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/25 18:50:45 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*	Фунция подсчета указветлей типа (char *) в массиве
 *  указателей (char **);
 *	При возвращении 0 значения выводтися ошибка.
 *	Либо (char **), либо (char **)[1] ссылается на NULL;
 */
size_t	ft_len_array(char **array)
{
	size_t	len;

	len = 0;
	if (array)
		while (array[len])
			len++;
	return (len);
}
