/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:51:06 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/11 15:06:25 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd	*new_cmd(char **tab, t_exec_line *structure)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->infile_fd = structure->infile;
	cmd->outfile_fd = structure->outfile;
	cmd->outfile_str = structure->outfile_str;
	cmd->infile_str = structure->infile_str;
	structure->infile = 0;
	structure->outfile = 1;
	cmd->cmd = tab;
	cmd->next = NULL;
	return (cmd);
}

void	add_back_cmd_list(t_cmd **cmd_list, t_cmd *cmd)
{
	t_cmd	*current;

	if (!(*cmd_list))
	{
		*cmd_list = cmd;
		return ;
	}
	current = *cmd_list;
	while (current->next)
	{
		current = current->next;
	}
	current->next = cmd;
}

int	size_tab(t_exec_line *structure)
{
	int		size;
	t_token	*current;

	size = 0;
	current = structure->current_token;
	while (current && current->type < 6)
	{
		if (current->type != 1)
			current = current->next->next;
		else
		{
			size += 1;
			current = current->next;
		}
	}
	return (size);
}

char	**create_cmd_tab(t_exec_line *structure)
{
	t_token	*current;
	int		i;
	char	**tab;

	tab = malloc(sizeof(char *) * (size_tab(structure) + 1));
	if (!tab)
		return (NULL);
	current = structure->current_token;
	i = 0;
	while (current && current->type < 6)
	{
		if (current->type != 1)
			current = current->next->next;
		else
		{
			tab[i] = current->str;
			current = current->next;
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

void	free_cmd_list(t_cmd *cmd_list)
{
	t_cmd	*current;
	t_cmd	*next;

	current = cmd_list;
	while (current)
	{
		next = current->next;
		free(current->cmd);
		free(current);
		current = next;
	}
}

// void	print_cmd_list(t_cmd *cmd_list)
// {
// 	t_cmd	*current;
// 	int		i;

// 	current = cmd_list;
// 	while (current)
// 	{
// 		i = 0;
// 		if (!current->cmd)
// 			printf("NULL\n");
// 		else
// 		{
// 			while (current->cmd[i])
// 			{
// 				printf("%s ", current->cmd[i]);
// 				i++;
// 			}
// 			printf("\n");
// 		}
// 		current = current->next;
// 	}
// }
