#include "../hdrs/minishell.h"

static int	ft_two_arrow_r( char **array, int *i)
{
	if (!(array[*i][2]))
		g_v.fd_out = open(array[++(*i)], O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		g_v.fd_out = open(array[*i] + 2, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (g_v.fd_out < 0)
	{
		perror("Fd out : ");
		return (1);
	}
	return (0);
}

static int	ft_one_arrow_r(char **array, int *i)
{
	if (array[*i][1] == '\0')
		g_v.fd_out = open(array[++(*i)], O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		g_v.fd_out = open(array[*i] + 1, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (g_v.fd_out < 0)
	{
		perror("Fd out : ");
		return (1);
	}
	return (0);
}

static int	ft_two_arrow_l(char **array, int *i)
{
	g_v.fd_util = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (g_v.fd_util < 0)
	{
		perror("Fd util : ");
		return (1);
	}
	if (!(array[*i][2]))
		ft_keyb_in(g_v.fd_util, array[++(*i)]);
	else
		ft_keyb_in(g_v.fd_util, array[*i] + 2);
	return (0);
}

static int	ft_one_arrow_l(char **array, int *i)
{
	if (!(array[*i][2]))
		g_v.fd_in = open(array[++(*i)], O_RDONLY);
	else
		g_v.fd_in = open(array[*i] + 2, O_RDONLY);
	if (g_v.fd_in < 0)
	{
		perror("Fd in : ");
		return (1);
	}
	return (0);
}

int	ft_open_fd(char **array, int *i)
{
	if (!ft_strncmp(">>", array[*i], 2) && array[*i][2] != '>' && array[*i][2] != '<')
	{
		if (ft_two_arrow_r(array, i))
			exit(1);
		close(g_v.fd_out);
	}
	else if (!ft_strncmp(">", array[*i], 1) && array[*i][1] != '>' && array[*i][1] != '<')
	{
		if (ft_one_arrow_r(array, i))
			exit(1);
		close(g_v.fd_out);
	}
	else if (!ft_strncmp("<<", array[*i], 2) && array[*i][2] != '>' && array[*i][2] != '<')
	{
		if (ft_two_arrow_l(array, i))
			exit(1);
		close(g_v.fd_in);
	}
	else if (!ft_strncmp("<", array[*i], 1) && array[*i][1] != '>' && array[*i][1] != '<')
	{
		if (ft_one_arrow_l(array, i))
			exit(1);
		close(g_v.fd_in);
	}
	else
		return (1);
	return (0);
}