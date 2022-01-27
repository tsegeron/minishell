#include "../hdrs/minishell.h"

typedef struct s_local
{
	size_t	i;
	size_t	j;
	size_t	count_ptrs;
	char	*ret;
	char	*tmp;
}	t_local;

static int	replace_dollar(t_local *q, char c)
{
	char	*tmp_s;
	char	*tmp;

	if (c == '$')
	{
		tmp_s = replace_dollar_signs(&q->ret[q->i]);
		tmp = ft_substr(q->ret, 0, q->i);
		free(q->ret);
		q->ret = ft_strjoin(NULL, tmp);
		free(tmp);
		if (tmp_s[0] == '\"')
			q->ret = ft_strjoin(q->ret, &tmp_s[1]);
		else
			q->ret = ft_strjoin(q->ret, tmp_s);
		free(tmp_s);
	}
	return (EXIT_SUCCESS);
}

static void	pull_str_from_quotes(t_local *q, char c)
{
	char	*tmp;
	char	*tmp2;

	if (q->ret[q->j] != '\"' && q->ret[q->j] != '\'')
		tmp = ft_substr(q->ret, q->j, q->i - q->j);
	else
		tmp = ft_strdup("");
	q->i++;
	q->j = q->i;
	if (c == '\'')
		while (q->ret[q->i] != '\'')
			q->i++;
	else
		while (q->ret[q->i] != '\"' && !replace_dollar(q, q->ret[q->i]))
			q->i++;
	tmp2 = ft_substr(q->ret, q->j, q->i - q->j); // строка между кавычек
	q->i++;
	q->tmp = ft_strjoin(q->tmp, tmp);
	q->tmp = ft_strjoin(q->tmp, tmp2);
	free(tmp);
	free(tmp2);
}

void	do_mthfoocking_redir_shit(char *check_me, char c, size_t *index)
{
	t_local	q;
	char	*tmp;

	q.i = 0;
	q.ret = ft_strdup(check_me);
	while (q.ret[q.i] == c)
		q.i++;
	if (q.i > 2 || !q.ret[q.i])
		return ;
	q.count_ptrs = q.i;
	q.tmp = NULL;
	while (q.ret[q.i] == ' ')
		q.i++;
	while (q.ret[q.i] && q.ret[q.i] != ' ')
	{
		q.j = q.i;
		while (q.ret[q.i] && !replace_dollar(&q, q.ret[q.i]) && q.ret[q.i] != '\'' \
		&& q.ret[q.i] != '\"' && q.ret[q.i] != ' ')
			q.i++;
		if (!q.ret[q.i] || q.ret[q.i] == ' ')
		{
			if (!tmp)
				tmp = ft_substr(q.ret, q.j, q.i - q.j);
			q.tmp = ft_strjoin(q.tmp, tmp);
			break;
		}
		else if (q.ret[q.i] == '\'' || q.ret[q.i] == '\"')
			pull_str_from_quotes(&q, q.ret[q.i]);
	}
	while (q.ret[q.i] == ' ')
		q.i++;
	(*index) += q.i;
	free(q.ret);
	if (c == '>')
		ft_open_fd(q.tmp, 0 + (int )q.count_ptrs);
	else
		ft_open_fd(q.tmp, 2 + (int )q.count_ptrs);
//	printf("filename >>%s<<\n", q.tmp);
	free(q.tmp);
}
