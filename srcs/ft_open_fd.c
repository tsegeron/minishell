/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:15:45 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/01 15:15:46 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

static int	ft_two_arrow_r(char *str)
{
	close(g_v.fd_out);
	g_v.fd_out = open(str, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (g_v.fd_out < 0)
	{
		perror("eBash: open");
		return (1);
	}
	return (0);
}

static int	ft_one_arrow_r(char *str)
{
	close(g_v.fd_out);
	g_v.fd_out = open(str, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (g_v.fd_out < 0)
	{
		perror("eBash: open");
		return (1);
	}
	return (0);
}

static int	ft_one_arrow_l(char *str)
{
	close(g_v.fd[0]);
	g_v.fd[0] = open(str, O_RDONLY);
	if (g_v.fd[0] < 0)
	{
		perror("eBash: open");
		return (1);
	}
	return (0);
}

static int	ft_two_arrow_l(char *str)
{
	int	var;

	g_v.ret_status = ft_keyb_in(str);
	if (g_v.ret_status == -3)
	{
		perror("eBash: open");
		return (1);
	}
	var = ft_one_arrow_l("here_doc");
	unlink("here_doc");
	if (var)
		return (1);
	return (0);
}

int	ft_open_fd(char *str, int status)
{
	if (status == 2)
	{
		if (ft_two_arrow_r(str))
			return (1);
	}
	else if (status == 1)
	{
		if (ft_one_arrow_r(str))
			return (1);
	}
	else if (status == 4)
	{
		if (ft_two_arrow_l(str))
			return (1);
		handle_signals();
	}
	else if (status == 3)
		if (ft_one_arrow_l(str))
			return (1);
	return (0);
}
