/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:11:30 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/11 10:25:22 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (!str[i])
		return (1);
	return (0);
}

void	shell_exit2(t_token *tokens_list, t_token *current, int *return_value
	, t_env *environ)
{
	if (current->next)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		*return_value = 1;
		return ;
	}
	else
	{
		free_environ(environ);
		rl_clear_history();
		*return_value = ft_atoi(current->str);
		freetokens2(tokens_list);
		exit(*return_value);
	}
}

void	shell_exit(t_token *tokens_list, int *return_value, t_env *environ)
{
	t_token	*current;

	current = tokens_list->next;
	if (!current)
	{
		free_environ(environ);
		rl_clear_history();
		freetokens2(tokens_list);
		exit(0);
	}
	else if (!is_number(current->str))
	{
		free_environ(environ);
		rl_clear_history();
		freetokens2(tokens_list);
		ft_putstr_fd("exit: numeric argument required\n", 2);
		exit (2);
	}
	else
		shell_exit2(tokens_list, current, return_value, environ);
}

void	shell_exit_fork(char **cmd, t_pipex *pipex)
{
	if (!cmd[1])
		close_all(0, pipex);
	else if (!is_number(cmd[1]))
	{
		ft_putstr_fd("exit: numeric argument required\n", 2);
		close_all(2, pipex);
	}
	else
	{
		if (cmd[2])
		{
			ft_putstr_fd("exit: too many arguments\n", 2);
			close_all(1, pipex);
		}
		else
			close_all(ft_atoi(cmd[1]), pipex);
	}
}
