/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:55:07 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/24 16:13:54 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	redirection(t_data *parsing)
{
	t_token *temp;

	temp = parsing->token_list;
	while (temp)
	{
		if (!temp->next)
			return (1);
		if (temp->type == INPUT)
			temp->next->fd = open(temp->next->str, O_RDONLY);
		else if (temp->type == OUTPUT)
			temp->next->fd = open(temp->next->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (temp->type == APPEND)
			temp->next->fd = open(temp->next->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
		temp = temp->next;
	}
	return (1);
}