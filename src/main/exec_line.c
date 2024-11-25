/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:00:02 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/12 11:10:39 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	command_creation(t_exec_line *structure)
{
	t_token	*current;
	t_token	*stock;
	int		flag;

	current = structure->memo;
	flag = 0;
	stock = structure->current_token;
	while (current && current->type != 6)
	{
		if (current->type == 1)
		{
			structure->current_token = current;
			add_back_cmd_list(&(structure->cmd_list),
				new_cmd(create_cmd_tab(structure), structure));
			flag = 1;
			break ;
		}
		else if (current->next && current->type != PIPE)
			current = current->next;
		current = current->next;
	}
	structure->current_token = stock;
	if (!flag)
		add_back_cmd_list(&(structure->cmd_list), new_cmd(NULL, structure));
}

void	exec_line_aux(t_exec_line *structure)
{
	if ((structure->current_token->type == 3
			|| structure->current_token->type == 5)
		&& structure->infile != -1 && structure->outfile != -1)
	{
		structure->outfile = structure->current_token->next->fd;
		structure->outfile_str = structure->current_token->next->str;
		structure->current_token = structure->current_token->next;
	}
	else if (structure->current_token->type == 6)
	{
		command_creation(structure);
		structure->memo = structure->current_token->next;
	}
}

void	init_structure(t_exec_line *structure, t_token *token_list)
{
	structure->tokens_list = token_list;
	structure->current_token = token_list;
	structure->memo = token_list;
	structure->infile = 0;
	structure->outfile = 1;
	structure->cmd_list = NULL;
	structure->infile_str = NULL;
	structure->outfile_str = NULL;
}

void	exec_line(t_token *token_list, t_env *environ, int	*return_value)
{
	t_exec_line	structure;

	init_structure(&structure, token_list);
	structure.cmd_list = NULL;
	while (structure.current_token)
	{
		if ((structure.current_token->type == 2
				|| structure.current_token->type == 4)
			&& structure.infile != -1 && structure.outfile != -1)
		{
			structure.infile = structure.current_token->next->fd;
			if (structure.current_token->type == 2)
				structure.infile_str = structure.current_token->next->str;
			else
				structure.infile_str = NULL;
			structure.current_token = structure.current_token->next;
		}
		else
			exec_line_aux(&structure);
		structure.current_token = structure.current_token->next;
	}
	command_creation(&structure);
	pipex(&structure, environ, return_value);
	free_cmd_list(structure.cmd_list);
}
