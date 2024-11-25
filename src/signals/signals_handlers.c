/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <abalasub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:22:38 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/12 19:27:47 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern volatile sig_atomic_t	g_signal_state;

void	handle_signal_readline(int sig)
{
	if (sig == SIGINT)
	{
		g_signal_state = sig;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	handle_signal_here_doc(int sig)
{
	if (SIGINT == sig)
		return ;
	if (sig == SIGQUIT)
		return ;
}

void	handle_signal_basic(int sig)
{
	g_signal_state = sig;
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
	}
	else if (sig == SIGQUIT)
	{
		printf("Quit (core dumped)");
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}
