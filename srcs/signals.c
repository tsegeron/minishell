/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:14:26 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/01 15:14:27 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

void	my_sigint(int signum)
{
	if (signum == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(2, "  \n", 3);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_v.ret_status = 1;
	}
}

void	my_sigquit(int signum)
{
	(void)signum;
	printf("Quit: %d\n", signum);
	g_v.ret_status = 131;
}

void	my_sigint_proc(int signum)
{
	if (signum == SIGINT)
	{
		write(2, "\n", 1);
		g_v.ret_status = 1;
	}
}

void	handle_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, my_sigint);
}

void	handle_signals_in_proc(void)
{
	signal(SIGQUIT, my_sigquit);
	signal(SIGINT, my_sigint_proc);
}
