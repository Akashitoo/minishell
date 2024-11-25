/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:52:11 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/11 10:18:18 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*rm_quote(char *str)
{
	int		i;
	int		size;
	char	*res;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			size++;
		i++;
	}
	i = 0;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (ft_putstr_fd("malloc rm quote\n", 2), NULL);
	size = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			res[size++] = str[i];
		i++;
	}
	res[size] = '\0';
	return (res);
}

int	pre_here_doc(t_token *temp)
{
	int		i;
	char	*new_str;

	i = 0;
	while (temp->str[i])
	{
		if (temp->str[i] == '\'' || temp->str[i] == '\"')
			temp->type = HD_CORRUPTED;
		i++;
	}
	if (temp->type != HD_CORRUPTED)
		return (1);
	new_str = rm_quote(temp->str);
	if (!new_str)
		return (0);
	free(temp->str);
	temp->str = new_str;
	return (1);
}

int	put_hd_in_pipe(t_token *temp)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
	{
		printf("pipe_error\n");
		return (0);
	}
	ft_putstr_fd(temp->next->str, pipefd[1]);
	close(pipefd[1]);
	if (!temp->next)
		return (0);
	temp->next->fd = pipefd[0];
	return (1);
}

int	ft_parsing2(t_data *parsing, t_token *temp)
{
	char	*str;

	if (temp->next->type == WORD)
	{
		if (!pre_here_doc(temp->next))
		{
			parsing->error_fatal = 1;
			return (0);
		}
		str = here_doc(temp->next->str);
		if (!str)
			return (0);
		free(temp->next->str);
		temp->next->str = str;
		if (!put_hd_in_pipe(temp))
			return (0);
	}
	else
		return (print_error_next(parsing), 0);
	return (1);
}

int	ft_parsing(t_data *parsing)
{
	t_token	*temp;

	temp = parsing->token_list;
	parsing->i = 0;
	if (temp->type == PIPE)
		return (print_error(parsing), 0);
	while (temp)
	{
		if (temp->type == HERE_DOC && temp->next)
		{
			if (!ft_parsing2(parsing, temp))
				return (0);
		}
		else if (temp->type > WORD && temp->type < PIPE)
		{
			if (!temp->next || temp->next->type != WORD)
				return (print_error_next(parsing), 0);
		}
		else if (temp->type == 6 && (!temp->next || temp->next->type >= 6))
			return (print_error_next(parsing), 0);
		parsing->i++;
		temp = temp->next;
	}
	return (1);
}
