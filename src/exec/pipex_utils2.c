/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <abalasub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:28:58 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/12 18:59:32 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	size_of_cmd_list(t_cmd	*cmd_list)
{
	t_cmd	*current;
	int		size;

	current = cmd_list;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	wait_all_process(t_cmd *cmd_list, int *status)
{
	int	nb_process;
	int	max;
	int	pid;
	int	res;

	max = 0;
	nb_process = size_of_cmd_list(cmd_list);
	while (nb_process)
	{
		pid = wait(status);
		if (pid > max)
		{
			max = pid;
			res = *status;
		}
		nb_process--;
	}
	if (WIFEXITED(res))
		return (WEXITSTATUS(res));
	else
	{
		kill(res, SIGKILL);
		return (130);
	}
}

void	no_command(t_pipex *pipex, int *return_value)
{
	free(pipex->envp);
	if (pipex->infile_str)
	{
		if (access(pipex->infile_str, R_OK) == -1)
		{
			ft_putstr_fd(pipex->infile_str, 2);
			ft_putstr_fd(": Permission denied\n", 2);
			*return_value = 1;
			return ;
		}
	}
	if (pipex->outfile_str)
	{
		if (access(pipex->outfile_str, W_OK) == -1)
		{
			ft_putstr_fd(pipex->outfile_str, 2);
			ft_putstr_fd(": Permission denied\n", 2);
			*return_value = 1;
			return ;
		}
	}
	*return_value = 0;
	return ;
}

void	close_all_fd(t_token *token_list)
{
	t_token	*current;

	current = token_list;
	while (current)
	{
		if (current->fd != 0 && current->fd != -1)
			close(current->fd);
		current = current->next;
	}
}
