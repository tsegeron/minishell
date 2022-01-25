/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_signs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:57:04 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/25 17:15:02 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

typedef struct s_local
{
	size_t	i;
	size_t	j;
	size_t	sign_pos;
	t_envp	*envp_ptr;
	char	*str;
	char	*a_sign;
	char	*a_sign_env;
	char	*itoa_res;
}	t_local;

static void	find_env_var(t_envp **envp_ptr, char *find_me)
{
	while (*envp_ptr)
	{
		if (!ft_strcmp(find_me, (*envp_ptr)->var))
			return ;
		*envp_ptr = (*envp_ptr)->next;
	}
}

static void	convert_line(t_local *q)
{
	find_env_var(&q->envp_ptr, q->a_sign_env);
	if (q->envp_ptr)
	{
		free(q->a_sign_env);
		q->str = ft_strjoin(q->str, q->envp_ptr->val);
	}
	else if (!q->envp_ptr && !ft_strcmp(q->a_sign_env, "?"))
	{
		free(q->a_sign_env);
		q->itoa_res = ft_itoa_uns(g_v.ret_status);
		q->str = ft_strjoin(q->str, q->itoa_res);
		free(q->itoa_res);
	}
	q->str = ft_strjoin(q->str, q->a_sign);
	free(q->a_sign);
}

char	*replace_dollar_signs(char *str)
{
	t_local	q;

	q.envp_ptr = g_v.envp;
	q.a_sign = ft_strdup(&str[1]);
	q.str = NULL;
	q.j = 0;
	while (q.a_sign[q.j] && ft_isalpha(q.a_sign[q.j]))
		q.j++;
	if (q.a_sign[0] == '?')
		q.j = 1;
	q.a_sign_env = ft_substr(q.a_sign, 0, q.j);
	free(q.a_sign);
	q.a_sign = ft_substr(str, q.j + 1, ft_strlen(str + q.j + 1));
	convert_line(&q);
	return (q.str);
}
