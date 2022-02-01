/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:14:37 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/01 15:14:40 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

void	implement_index(size_t *i, int *j, char *str, char c)
{
	if (c == ' ')
	{
		if ((*j) != -2)
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

size_t	count_words(char *str)
{
	size_t	count;
	size_t	i;
	int		st;

	st = -2;
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

int	replace_dollar(t_quotes *q, char c)
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

static int	set_pipe_as_invalid(t_quotes *q, char c)
{
	char	*tmp;
	char	*tmp2;

	if (q->trim[q->i] == '|' && q->trim[q->i - 1] == c && \
	q->trim[q->i + 1] == c && q->trim[q->i - 2] == ' ' && \
	(q->trim[q->i + 2] == ' ' || !q->trim[q->i + 2]))
	{
		tmp = ft_substr(q->trim, 0, q->i + 1);
		tmp2 = ft_substr(q->trim, q->i + 1, ft_strlen(&q->trim[q->i]));
		tmp = ft_strjoin(tmp, "|");
		tmp = ft_strjoin(tmp, tmp2);
		free(q->trim);
		q->trim = ft_strdup(tmp);
		free(tmp);
		free(tmp2);
		q->i++;
	}
	return (EXIT_SUCCESS);
}

void	pull_str_from_quotes(t_quotes *q, char c)
{
	q->i++;
	q->j = q->i;
	if (c == '\'')
		while (!set_pipe_as_invalid(q, c) && q->trim[q->i] != '\'')
			q->i++;
	else
	{
		while (!set_pipe_as_invalid(q, c) && q->trim[q->i] != '\"')
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
