/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyb_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:14:12 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/01 15:14:15 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

void	sign_here_doc(int i)
{
	if (i == SIGINT)
	{
		write(2, "> ", 2);
		exit(1);
	}
}

static int	ft_here_doc(char *str, int fd)
{
	char	*buffer;

	buffer = ft_strdup("\t");
	if (!buffer || !str)
		exit(EXIT_FAILURE);
	signal(SIGINT, sign_here_doc);
	while (ft_strcmp(str, buffer) > 0 || ft_strcmp(str, buffer) < 0)
	{
		free(buffer);
		buffer = readline("> ");
		if (!buffer)
			break ;
		if (ft_strcmp(str, buffer))
		{
			write(fd, buffer, ft_strlen(buffer));
			write(fd, "\n", 1);
		}
	}
	if (buffer)
		free(buffer);
	close(fd);
	exit (EXIT_SUCCESS);
}

int	ft_keyb_in(char *str)
{
	int	fd;
	int	pid;
	int	status;

	fd = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("eBash: open");
		return (-3);
	}
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid < 0)
	{
		perror("eBash");
		return (1);
	}
	if (!pid)
		return (ft_here_doc(str, fd));
	wait(&status);
	g_v.ret_status = WEXITSTATUS(status);
	handle_signals();
	close(fd);
	return (g_v.ret_status);
}
