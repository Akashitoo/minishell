/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <abalasub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:33:28 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/12 19:21:29 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

volatile sig_atomic_t	g_signal_state;

char	*my_readline(void)
{
	char	*res;

	signal_init_readline();
	res = readline(">minishell$ ");
	signal_init_basic();
	return (res);
}

int	minishell_bis(t_token *tokens_list, t_env **environ, int *return_value)
{
	if (tokens_list)
	{
		check_builtins(environ, &tokens_list, return_value);
		freetokens2(tokens_list);
		if (return_value < 0)
		{
			*return_value = 1;
			return (0);
		}
	}
	return (1);
}

int	signal_return_value(int	*return_value)
{
	if (g_signal_state != 0)
	{
		*return_value = g_signal_state + 128;
		g_signal_state = 0;
	}
	return (*return_value);
}

void	minishell(t_env **environ, int return_value)
{
	char	*prompt;
	t_token	*tokens_list;
	int		flag;

	flag = 1;
	g_signal_state = 0;
	while (1)
	{
		tokens_list = NULL;
		prompt = my_readline();
		return_value = signal_return_value(&return_value);
		if (prompt == NULL)
			break ;
		if (prompt[0] != '\0')
		{
			add_history(prompt);
			tokens_list = parsing_extended(prompt, &return_value, *environ);
		}
		free(prompt);
		if (!minishell_bis(tokens_list, environ, &return_value))
			break ;
		rl_on_new_line();
	}
}
