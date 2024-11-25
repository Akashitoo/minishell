/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <abalasub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:39:25 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/12 16:51:09 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	shell_cd(t_token *tokens_list, int *return_value)
{
	t_token	*current;

	*return_value = 0;
	current = tokens_list->next;
	if (current && current->next)
	{
		printf("cd: too many arguments\n");
		*return_value = 1;
	}
	else if (!current)
		chdir("/home/abalasub");
	else if (access(current->str, F_OK | X_OK) == 0)
		chdir(current->str);
	else if (access(current->str, F_OK))
	{
		printf("cd: no such file or directory: %s\n", current->str);
		*return_value = 1;
	}
	else if (access(current->str, X_OK))
	{
		printf("cd: Permission denied: %s\n", current->str);
		*return_value = 1;
	}
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i + 1);
}

void	shell_cd_fork(char **cmd, t_pipex *pipex)
{
	if (tablen(cmd) > 3)
	{
		ft_putstr_fd("cd : too many arguments\n", 2);
		close_all(1, pipex);
	}
	else if (!cmd[1])
		chdir("/home/abalasub");
	else if (access(cmd[1], F_OK))
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd("\n", 2);
		close_all(1, pipex);
	}
	else if (access(cmd[1], X_OK))
	{
		ft_putstr_fd("cd: Permission denied: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd("\n", 2);
		close_all(1, pipex);
	}
	else if (access(cmd[1], F_OK | X_OK) == 0)
		chdir(cmd[1]);
	close_all(0, pipex);
}
