/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:15:04 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/01 15:15:06 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

static int	do_actual_separating(char **str, char **tmp, char **tmp2, int *i)
{
	(*tmp) = ft_substr((*str), 0, (*i));
	if (!(*tmp))
		return (EXIT_FAILURE);
	(*tmp) = ft_strjoin((*tmp), " | ");
	if (!(*tmp))
		return (EXIT_FAILURE);
	while ((*str)[++(*i)] == ' ')
		;
	(*tmp2) = ft_substr((*str), (*i), ft_strlen(&(*str)[(*i)]));
	if (!(*tmp2))
		return (EXIT_FAILURE);
	(*tmp) = ft_strjoin((*tmp), (*tmp2));
	free((*tmp2));
	if (!(*tmp))
		return (EXIT_FAILURE);
	free(*str);
	*str = ft_strdup((*tmp));
	free((*tmp));
	if (!*str)
		return (EXIT_FAILURE);
	(*i) += 3;
	return (EXIT_SUCCESS);
}

void	separate_pipe_if_needed(char **str)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	while ((*str)[i])
	{
		while ((*str)[i] && (*str)[i] != '|')
		{
			if ((*str)[i] == '\'')
				while ((*str)[++i] != '\'')
					;
			if ((*str)[i] == '\"')
				while ((*str)[++i] != '\"')
					;
			i++;
		}
		if (!(*str)[i] || i == 0 || (((*str)[i - 1] == ' ') && \
		((*str)[i + 1] && (*str)[i + 1] == ' ')))
			return ;
		if (do_actual_separating(str, &tmp, &tmp2, &i))
			return ;
	}
}

static int	handle_invalid_pipes(int *i, int *cur)
{
	free(g_v.av[(*i)]);
	g_v.av[(*i)] = ft_strdup("|");
	if (!g_v.av[(*i)])
		return (EXIT_FAILURE);
	while (g_v.av[++(*i)] && ft_strcmp(g_v.av[(*i)], "|"))
	{
		if (!ft_strcmp(g_v.av[(*i)], "||"))
		{
			free(g_v.av[(*i)]);
			g_v.av[(*i)] = ft_strdup("|");
			if (!g_v.av[(*i)])
				return (EXIT_FAILURE);
		}
		g_v.av[(*cur)] = ft_strjoin(g_v.av[(*cur)], " ");
		if (!g_v.av[(*cur)])
			return (EXIT_FAILURE);
		g_v.av[(*cur)] = ft_strjoin(g_v.av[(*cur)], g_v.av[(*i)]);
		if (!g_v.av[(*cur)])
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	check_for_invalid_pipes(void)
{
	int	i;
	int	j;
	int	cur;
	int	save;

	i = 0;
	while (g_v.av[i])
	{
		if (!ft_strcmp(g_v.av[i], "||"))
		{
			cur = i;
			if (handle_invalid_pipes(&i, &cur))
				return ;
			j = i;
			while (--j > cur)
			{
				free(g_v.av[j]);
				g_v.av[j] = NULL;
			}
			save = i - 1;
			while (g_v.av[++save])
				g_v.av[++j] = ft_strdup(g_v.av[save]);
		}
		i++;
	}
}
