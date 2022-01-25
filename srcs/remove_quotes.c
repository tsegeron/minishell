/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:01:28 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/25 20:20:18 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

typedef struct s_local
{
	size_t	i;
	size_t	j;
	int		s;
	char	*trim;
	char	*tmp;
	char	*tmp_s;
}	t_local;

static void	implement_index(size_t *i, int *j, char *str, char c)
{
	if (c == ' ')
	{
		if ((*j) != -1)
			(*j)++;
		while (str[*i] == ' ')
			(*i)++;
	}
	else if (c == '\'')
	{
		while (str[++(*i)] != '\'')
			;
		(*i)++;
	}
	else
	{
		while (str[++(*i)] != '\"')
			;
		(*i)++;
	}
}

static size_t	count_words(char *str)
{
	size_t	count;
	size_t	i;
	int		st;

	st = -1;
	if (!str)
		return (0);
	count = 1;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '\"')
			i++;
		if (str[i] == ' ')
		{
			count++;
			implement_index(&i, &st, str, ' ');
		}
		else if (str[i] == '\'')
			implement_index(&i, &st, str, '\'');
		else if (str[i] == '\"')
			implement_index(&i, &st, str, '\"');
	}
	return (count);
}

static int	replace_dollar(t_local *q, char c)
{
	if (c == '$')
	{
		q->tmp_s = replace_dollar_signs(&q->trim[q->i]);
		q->tmp = ft_substr(q->trim, 0, q->i);
		free(q->trim);
		q->trim = ft_strjoin(NULL, q->tmp);
		free(q->tmp);
		if (q->tmp_s[0] == '\"')
			q->trim = ft_strjoin(q->trim, &q->tmp_s[1]);
		else
			q->trim = ft_strjoin(q->trim, q->tmp_s);
		free(q->tmp_s);
	}
	return (EXIT_SUCCESS);
}

static void	pull_str_from_quotes(t_local *q, char c)
{
	q->i++;
	q->j = q->i;
	if (c == '\'')
		while (q->trim[q->i] != '\'')
			q->i++;
	else
	{
		while (q->trim[q->i] != '\"')
		{
			if (q->trim[q->i] == '$')
				replace_dollar(q, '$');
			q->i++;
		}
	}
	q->tmp = ft_substr(q->trim, q->j, q->i - q->j);
	q->i++;
	g_v.av[q->s] = ft_strjoin(g_v.av[q->s], q->tmp);
	free(q->tmp);
	if (q->trim[q->i] && q->trim[q->i] == ' ')
	{
		q->s++;
		while (q->trim[q->i] == ' ')
			q->i++;
	}
}

void	remove_quotes_and_split(char *str)
{
	t_local	q;

	q.trim = ft_strtrim(str, " ");
	g_v.av = (char **) ft_calloc(sizeof(char *), count_words(q.trim) + 1);
	q.s = 0;
	q.i = 0;
	while (q.trim[q.i])
	{
		if (q.trim[q.i] == ' ')
			implement_index(&q.i, &q.s, q.trim, ' ');
		else if (q.trim[q.i] == '\'')
			pull_str_from_quotes(&q, '\'');
		else if (q.trim[q.i] == '\"')
			pull_str_from_quotes(&q, '\"');
		q.j = q.i;
		while (q.trim[q.i] && !replace_dollar(&q, q.trim[q.i]) && \
		q.trim[q.i] != ' ' && q.trim[q.i] != '\'' && q.trim[q.i] != '\"')
			q.i++;
		q.tmp = ft_substr(q.trim, q.j, q.i - q.j);
		g_v.av[q.s] = ft_strjoin(g_v.av[q.s], q.tmp);
		free(q.tmp);
	}
	free(q.trim);
}
