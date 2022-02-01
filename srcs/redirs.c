/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:14:54 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/01 15:14:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

typedef struct s_local
{
	size_t	i;
	size_t	j;
	size_t	count_ptrs;
	char	*ret;
	char	*tmp;
	char	*tmp2;
}	t_local;

static int	replace_dollar1(t_local *q, char c)
{
	char	*tmp_s;
	char	*tmp;

	if (c == '$')
	{
		tmp_s = replace_dollar_signs(&q->ret[q->i]);
		if (!tmp_s)
			return (-1);
		tmp = ft_substr(q->ret, 0, q->i);
		if (!tmp)
			return (-1);
		free(q->ret);
		q->ret = ft_strjoin(NULL, tmp);
		free(tmp);
		if (tmp_s[0] == '\"')
			q->ret = ft_strjoin(q->ret, &tmp_s[1]);
		else
			q->ret = ft_strjoin(q->ret, tmp_s);
		if (!q->ret)
			return (-1);
		free(tmp_s);
	}
	return (EXIT_SUCCESS);
}

static void	pull_str_from_quotes1(t_local *q, char c)
{
	char	*tmp;
	char	*tmp2;

	if (q->ret[q->j] != '\"' && q->ret[q->j] != '\'')
		tmp = ft_substr(q->ret, q->j, q->i - q->j);
	else
		tmp = ft_strdup("");
	if (!tmp)
		return ;
	q->i++;
	q->j = q->i;
	if (c == '\'')
		while (q->ret[q->i] != '\'')
			q->i++;
	else
		while (q->ret[q->i] != '\"' && !replace_dollar1(q, q->ret[q->i]))
			q->i++;
	tmp2 = ft_substr(q->ret, q->j, q->i - q->j);
	q->i++;
	q->tmp = ft_strjoin(q->tmp, tmp);
	q->tmp = ft_strjoin(q->tmp, tmp2);
	if (tmp2)
		free(tmp2);
	if (q->tmp)
		free(tmp);
}

static int	count_redirs_and_skip_spaces(char *check_me, char c, t_local *q)
{
	q->i = 0;
	q->ret = ft_strdup(check_me);
	if (!q->ret)
		return (EXIT_FAILURE);
	while (q->ret[q->i] == c)
		q->i++;
	if (q->i > 2 || !q->ret[q->i])
	{
		free(q->ret);
		return (EXIT_FAILURE);
	}
	q->count_ptrs = q->i;
	q->tmp = NULL;
	q->tmp2 = NULL;
	while (q->ret[q->i] == ' ')
		q->i++;
	return (EXIT_SUCCESS);
}

void	move_index_and_open_fd(t_local *q, char c, size_t *index, int *r_s)
{
	while (q->ret[q->i] == ' ')
		q->i++;
	(*index) += q->i;
	free(q->ret);
	if (c == '>')
	{
		*r_s = 1;
		ft_open_fd(q->tmp, 0 + (int )q->count_ptrs);
	}
	else
		ft_open_fd(q->tmp, 2 + (int )q->count_ptrs);
	free(q->tmp);
}

void	do_mthf_redir_shit(char *check_me, char c, size_t *index, int *r_s)
{
	t_local	q;

	if (count_redirs_and_skip_spaces(check_me, c, &q))
		return ;
	while (q.ret[q.i] && q.ret[q.i] != ' ')
	{
		q.j = q.i;
		while (q.ret[q.i] && !replace_dollar1(&q, q.ret[q.i]) && \
		q.ret[q.i] != '\'' && q.ret[q.i] != '\"' && q.ret[q.i] != ' ')
			q.i++;
		if (!q.ret[q.i] || q.ret[q.i] == ' ')
		{
			q.tmp2 = ft_substr(q.ret, q.j, q.i - q.j);
			if (!q.tmp2)
				return ;
			q.tmp = ft_strjoin(q.tmp, q.tmp2);
			free(q.tmp2);
			if (!q.tmp)
				return ;
			break ;
		}
		else if (q.ret[q.i] == '\'' || q.ret[q.i] == '\"')
			pull_str_from_quotes1(&q, q.ret[q.i]);
	}
	move_index_and_open_fd(&q, c, index, r_s);
}
