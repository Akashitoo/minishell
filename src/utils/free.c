/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <abalasub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:51:27 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/12 16:25:33 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//sig_atomic_t	g_signal = 0;
void	close_all(int exit_value, t_pipex *pipex)
{
	free_cmd_list(pipex->cmd_list);
	free(pipex->envp);
	freetokens2(pipex->tokens_list);
	free_environ(pipex->environ);
	rl_clear_history();
	exit(exit_value);
}

void	freetokens2(t_token	*token_list)
{
	t_token	*temp;

	if (token_list != NULL)
	{
		while (token_list)
		{
			temp = token_list;
			free(token_list->str);
			if (temp->fd != 0 && temp->fd != -1)
				close(temp->fd);
			token_list = token_list->next;
			free(temp);
		}
	}
}

void	freetab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		ft_putstr_fd("freetab appeler avec un tableau null", 2);
	else
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

void	freetabn(char **tab, int n)
{
	int	i;

	i = 0;
	if (!tab)
		ft_putstr_fd("freetabn appeler avec un tableau null", 2);
	else
	{
		while (i < n && tab[i])
			free(tab[i++]);
		free(tab);
	}
}

void	freetokens(t_token *token_list)
{
	t_token	*temp;

	if (token_list != NULL)
	{
		while (token_list)
		{
			temp = token_list;
			free(token_list->str);
			token_list = token_list->next;
			free(temp);
		}
	}
}
