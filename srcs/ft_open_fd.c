#include "../hdrs/minishell.h"

static int	ft_two_arrow_r(char *str)
{
	close(g_v.fd_out);
	g_v.fd_out = open(str + 2, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (g_v.fd_out < 0)
	{
		perror("Fd out : ");
		return (1);
	}
	return (0);
}

static int	ft_one_arrow_r(char *str)
{
	close(g_v.fd_out);
	g_v.fd_out = open(str + 1, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (g_v.fd_out < 0)
	{
		perror("Fd out : ");
		return (1);
	}
	return (0);
}

static int	ft_two_arrow_l(char *str)
{
	close(g_v.fd_util);
	g_v.fd_util = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (g_v.fd_util < 0)
	{
		perror("Fd util : ");
		return (1);
	}
	ft_keyb_in(g_v.fd_util, str + 2);
	return (0);
}

static int	ft_one_arrow_l(char *str)
{
	close(g_v.fd[0]);
	g_v.fd[0] = open(str + 2, O_RDONLY);
	if (g_v.fd[0] < 0)
	{
		perror("Fd in : ");
		return (1);
	}
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
	}
	else if (status == 3)
		if (ft_one_arrow_l(str))
			return (1);
	return (0);
}
