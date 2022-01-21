/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:17:37 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/18 21:26:48 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

static char	*find_return(char *path, int status)
{
	if (!status)
	{
		ft_putendl_fd(path, 1);
		free(path);
		return (NULL);
	}
	else
	{
		path = ft_strjoin(path, "\n");
		return (path);
	}
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
