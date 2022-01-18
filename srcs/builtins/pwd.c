/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:17:37 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/18 15:32:29 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

static char *find_return(char **path, int status)
{
	if (!status)
	{
		ft_putendl_fd(*path, 1);
		free(*path);
		return (NULL);
	}
	else
		return (*path);
}

char	*pwd(int status)
{
	char	*path;
	char	*buf;
	size_t	size;

	size = 20;
	buf = ft_calloc(sizeof(char), size);
	path = getcwd(buf, size);
	while (!path)
	{
		free(buf);
		size += 20;
		buf = ft_calloc(sizeof(char), size);
		path = getcwd(buf, size);
	}
	size = ft_strlen(path);
	free(path);
	ft_realloc((void **)&buf, size);
	path = getcwd(buf, size);
	free(buf);
	return (find_return(&path, status));
}
