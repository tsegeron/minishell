/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:17:37 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/21 19:05:25 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

static char	*find_return(char *path, int status)
{
	if (!status)
	{
		ft_putendl_fd(path, STDOUT_FILENO);
		free(path);
		return (NULL);
	}
	else
		return (path);
}

char	*b_pwd(int status)
{
	char	*buf;
	size_t	size;

	size = 20;
	buf = malloc(sizeof(char) * size);
	if (!buf)
		return (NULL);
	while (!getcwd(buf, size))
	{
		free(buf);
		size += 20;
		buf = malloc(sizeof(char) * size);
	}
	size = ft_strlen(buf) + 1;
	free(buf);
	buf = malloc(sizeof(char) * size);
	if (!buf)
		return (NULL);
	return (find_return(getcwd(buf, size), status));
}
