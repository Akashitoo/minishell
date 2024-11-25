/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:44:39 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/08 19:52:56 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	shell_env(t_env *env, int *return_value,
	int write_fd, t_token *tokens_list)
{
	t_env	*current;

	if (!env)
		return ;
	if (tokens_list->next)
	{
		ft_putstr_fd("env: ‘", 2);
		ft_putstr_fd(tokens_list->next->str, 2);
		ft_putstr_fd("’: No such file or directory\n", 2);
		return ;
	}
	current = env;
	while (current)
	{
		ft_putstr_fd(current->str, write_fd);
		ft_putstr_fd("\n", write_fd);
		current = current->next;
	}
	*return_value = 0;
}

void	shell_env_fork(t_pipex *pipex, char **cmd_options)
{
	int		i;
	char	**env;

	env = pipex->envp;
	if (!env)
		close_all(1, pipex);
	if (cmd_options[1])
	{
		ft_putstr_fd("env: ‘", 2);
		ft_putstr_fd(cmd_options[1], 2);
		ft_putstr_fd("’: No such file or directory\n", 2);
		close_all(1, pipex);
	}
	i = 0;
	while (env[i])
	{
		ft_putstr_fd(env[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	close_all(0, pipex);
}
