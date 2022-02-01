/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:01:28 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/30 23:59:59 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

void	check_for_empty_lines(void)
{
	int	i;

	i = -1;
	while (g_v.av[++i])
		;
	if (i && !g_v.av[--i][0])
	{
		free(g_v.av[i]);
		g_v.av[i] = NULL;
	}
}

static int	trim_and_init(t_quotes *q, char *str)
{
	q->r_s = 0;
	q->tmp = ft_strtrim(str, " ");
	if (!q->tmp)
		return (EXIT_FAILURE);
	separate_pipe_if_needed(&q->tmp);
	q->trim = ft_strtrim(q->tmp, " ");
	free(q->tmp);
	if (!q->trim)
		return (EXIT_FAILURE);
	g_v.av = (char **) ft_calloc(sizeof(char *), count_words(q->trim) + 1);
	if (!g_v.av)
		return (EXIT_FAILURE);
	g_v.av[count_words(q->trim)] = NULL;
	q->s = 0;
	q->i = 0;
	return (EXIT_SUCCESS);
}

static void	handle_cases(t_quotes *q)
{
	if (q->trim[q->i] == ' ')
		implement_index(&q->i, &q->s, q->trim, ' ');
	else if (q->trim[q->i] == '<' || q->trim[q->i] == '>')
		do_mthf_redir_shit(&q->trim[q->i], q->trim[q->i], &q->i, &q->r_s);
	else if (q->trim[q->i] == '\'')
		pull_str_from_quotes(q, '\'');
	else if (q->trim[q->i] == '\"')
		pull_str_from_quotes(q, '\"');
}

static void	skip_till_case(t_quotes *q)
{
	while (q->trim[q->i] && !replace_dollar(q, q->trim[q->i]) && \
		q->trim[q->i] != ' ' && q->trim[q->i] != '\'' && \
		q->trim[q->i] != '\"' && q->trim[q->i] != '<' && q->trim[q->i] != '>')
	{
		if (q->trim[q->i] == '|' && q->r_s)
		{
			ft_pipex(g_v.av);
			g_v.fd[0] = dup(STDIN_FILENO);
			g_v.fd_out = dup(STDOUT_FILENO);
			q->del = 0;
			while (g_v.av[q->del] && g_v.av[q->del][0])
			{
				free(g_v.av[q->del]);
				g_v.av[q->del++] = NULL;
			}
			q->s = -1;
			q->r_s = 0;
			q->i++;
			q->j = q->i;
			break ;
		}
		q->i++;
	}
}

void	remove_quotes_and_split(char *str)
{
	t_quotes	q;

	if (trim_and_init(&q, str))
		return ;
	g_v.pipe_stat = 0;
	while (q.trim[q.i])
	{
		handle_cases(&q);
		q.j = q.i;
		skip_till_case(&q);
		if (q.i != q.j)
		{
			q.tmp = ft_substr(q.trim, q.j, q.i - q.j);
			g_v.av[q.s] = ft_strjoin(g_v.av[q.s], q.tmp);
			free(q.tmp);
		}
	}
	check_for_invalid_pipes();
	check_for_empty_lines();
	free(q.trim);
}
