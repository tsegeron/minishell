/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseastar <mseastar@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:26:20 by mseastar          #+#    #+#             */
/*   Updated: 2022/01/22 16:22:44 by mseastar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

int	ft_check_fd(int fd1, int fd2)
{
	if (fd1 < 0 || read(fd1, 0, 0) < 0)
	{
		write(2, "File was not found or you have no rules.\n", 41);
		return (1);
	}
	if (fd2 < 0 || read(fd2, 0, 0) < 0)
	{
		write(2, "File was not created or you have no rules.\n", 43);
		return (1);
	}
	return (0);
}
