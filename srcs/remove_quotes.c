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

static int	set_pipe_as_invalid(t_local *q)
{
	char	*tmp;
	char	*tmp2;

	if (q->trim[q->i] == '|')
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

static void	pull_str_from_quotes(t_local *q, char c)
{
	q->i++;
	q->j = q->i;
	if (c == '\'')
		while (!set_pipe_as_invalid(q) && q->trim[q->i] != '\'')
			q->i++;
	else
	{
		while (!set_pipe_as_invalid(q) && q->trim[q->i] != '\"')
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

void	separate_pipe_if_needed(char **str)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
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
	if (!(*str)[i] || i == 0 || (((*str)[i - 1] == ' ') && ((*str)[i + 1] && (*str)[i + 1] == ' ')))
		return ;
	tmp = ft_substr((*str), 0, i);
	tmp = ft_strjoin(tmp, " | ");
	while ((*str)[++i] == ' ')
		;
	tmp2 = ft_substr((*str), i, ft_strlen(&(*str)[i]));
	tmp = ft_strjoin(tmp, tmp2);
	free(*str);
	*str = ft_strdup(tmp);
	free(tmp);
	free(tmp2);
}

void	check_for_invalid_pipes(void)
{
	char	*tmp;
	char	*tmp2;
	int		i;
	int		cur;
	int		j;
	int		p;
	int		st;
	int		save;
	int		q;
	int		w;

	i = 0;
	while (g_v.av[i])
	{
		j = -1;
		p = 0;
		tmp = NULL;
		while (g_v.av[i][++j])
		{
			if (g_v.av[i][j] == '|' && g_v.av[i][j + 1] == '|')
			{
				tmp = ft_substr(g_v.av[i], p, ++j);
				tmp = ft_strjoin(tmp, &(g_v.av[i][j + 2]));
				while (g_v.av[i][j] == '|')
					j++;
				p = j + 1;
			}
		}
		if (tmp)
		{
			free(g_v.av[i]);
			g_v.av[i] = ft_strdup(tmp);
			free(tmp);
			cur = i;
			while (g_v.av[i + 1] && ft_strcmp(g_v.av[i + 1], "|"))
			{
				q = -1;
				w = 0;
				i++;
				while (g_v.av[i][++q])
				{
//						printf(">>%s\n", &g_v.av[i][q]);
					if (g_v.av[i][q] == '|' && g_v.av[i][q + 1] == '|')
					{
						tmp2 = ft_substr(g_v.av[i], w, ++q);
//						printf(">>%s<<", tmp2);
						tmp2 = ft_strjoin(tmp2, &(g_v.av[i][q + 3]));
//						printf(">>%s<<", &g_v.av[i][q + 2]);
						while (g_v.av[i][q] == '|')
							q++;
						w = q + 1;
						free(g_v.av[i]);
						g_v.av[i] = ft_strdup(tmp2);
						free(tmp2);
					}
				}
				g_v.av[cur] = ft_strjoin(g_v.av[cur], " ");
				g_v.av[cur] = ft_strjoin(g_v.av[cur], g_v.av[i]);
			}
			st = cur;
			save = cur;
			while (++cur < i + 1)
			{
				free(g_v.av[cur]);
				g_v.av[cur] = NULL;
			}
			if (g_v.av[i + 1])
			{
				while (g_v.av[++i])
				{
					if (!g_v.av[st + 1])
						g_v.av[++st] = ft_strdup(g_v.av[i]);
					else
					{
						free(g_v.av[++st]);
						g_v.av[st] = ft_strdup(g_v.av[i]);
					}
				}
				while (++st < i)
				{
					free(g_v.av[st]);
					g_v.av[st] = NULL;
				}
			}
			i = save;
		}
		i++;
	}
}

void	remove_quotes_and_split(char *str)
{
	t_local	q;

	q.trim = ft_strtrim(str, " ");
	separate_pipe_if_needed(&q.trim);
	g_v.av = (char **) ft_calloc(sizeof(char *), count_words(q.trim) + 1);
	q.s = 0;
	q.i = 0;
	while (q.trim[q.i])
	{
		if (q.trim[q.i] == ' ')
			implement_index(&q.i, &q.s, q.trim, ' ');
		else if (q.trim[q.i] == '<' || q.trim[q.i] == '>')
			do_mthfoocking_redir_shit(&q.trim[q.i], q.trim[q.i], &q.i);
		else if (q.trim[q.i] == '\'')
			pull_str_from_quotes(&q, '\'');
		else if (q.trim[q.i] == '\"')
			pull_str_from_quotes(&q, '\"');
		q.j = q.i;
		while (q.trim[q.i] && !replace_dollar(&q, q.trim[q.i]) && \
		q.trim[q.i] != ' ' && q.trim[q.i] != '\'' && q.trim[q.i] != '\"' && \
		q.trim[q.i] != '<' && q.trim[q.i] != '>')
			q.i++;
		q.tmp = ft_substr(q.trim, q.j, q.i - q.j);
		g_v.av[q.s] = ft_strjoin(g_v.av[q.s], q.tmp);
		free(q.tmp);
	}
//	for(int i = 0; g_v.av[i]; i++)
//		printf("%s\n", g_v.av[i]);
	check_for_invalid_pipes();
//	printf("\n");
	for(int i = 0; g_v.av[i]; i++)
		printf("%s\n", g_v.av[i]);
	exit(0);
	free(q.trim);
}
