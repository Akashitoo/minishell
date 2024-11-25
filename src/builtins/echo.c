/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <abalasub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:38:57 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/12 16:52:14 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_full_n(char *str)
{
	int	i;

	i = 2;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	get_write_fd(t_token *tokens_list)
{
	t_token	*current;
	int		res;

	res = 1;
	current = tokens_list;
	while (current)
	{
		if (current->type == OUTPUT || current->type == APPEND)
			res = current->next->fd;
		current = current->next;
	}
	return (res);
}

void	shell_echo_bis(t_token	**current, int write_fd)
{
	if ((*current)->type == WORD)
	{
		ft_putstr_fd((*current)->str, write_fd);
		if ((*current)->next)
			ft_putstr_fd(" ", write_fd);
		*current = (*current)->next;
	}
	else
	{
		*current = (*current)->next;
		if (*current)
			*current = (*current)->next;
	}
}

void	shell_echo(t_token *tokens_list, int *return_value, int write_fd)
{
	t_token	*current;
	int		nl;

	nl = 1;
	current = tokens_list->next;
	while (current && (ft_strncmp(current->str, "-n", 2) == 0
			&& is_full_n(current->str)))
	{
		nl = 0;
		current = current->next;
	}
	while (current && current->type != PIPE)
		shell_echo_bis(&current, write_fd);
	if (nl)
		ft_putstr_fd("\n", write_fd);
	*return_value = 0;
}

void	shell_echo_fork(char **cmd, t_pipex *pipex)
{
	int	nl;
	int	i;

	nl = 1;
	i = 1;
	while (cmd[i] && (ft_strncmp(cmd[i], "-n", 2) == 0)
		&& is_full_n(cmd[i]))
	{
		nl = 0;
		i++;
	}
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], 1);
		if (cmd[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (nl)
		ft_putstr_fd("\n", 1);
	close_all(0, pipex);
}
