/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:55:07 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/11 18:10:20 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	redirection(t_data *parsing)
{
	t_token	*temp;
	int		flag;

	temp = parsing->token_list;
	flag = 1;
	while (temp)
	{
		if (!temp->next)
			break ;
		if (temp->type == INPUT && flag)
			temp->next->fd = open(temp->next->str, O_RDONLY);
		else if (temp->type == OUTPUT && flag)
			temp->next->fd = open(temp->next->str,
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (temp->type == APPEND && flag)
			temp->next->fd = open(temp->next->str,
					O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (flag == 0 && temp->type == PIPE)
			flag = 1;
		if (temp->next->fd == -1)
			flag = 0;
		temp = temp->next;
	}
}
