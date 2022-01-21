/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:17:04 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:05:25 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					m;
	int					i;

	res = 0;
	m = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		m = -1 * m;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] > 47) && (str[i] < 58))
		res = res * 10 + str[i++] - 48;
	if (res > 9223372036854775807 && m > 0)
		return (-1);
	else if (res > 9223372036854775807 && m < 0)
		return (0);
	return ((int)res * m);
}
