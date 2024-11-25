/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:19:58 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/04 16:22:41 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_error_next(t_data *parsing)
{
	t_token	*token;

	token = go_through_list(parsing->token_list, parsing->i);
	*(parsing->return_value) = 2;
	if (token->next)
	{
		ft_putstr_fd("bash: syntax error near unexpected token '", 2);
		ft_putstr_fd(token->next->str, 2);
		ft_putstr_fd("'\n", 2);
	}
	else
	{
		ft_putstr_fd("bash: syntax error near unexpected token '", 2);
		ft_putstr_fd("newline", 2);
		ft_putstr_fd("'\n", 2);
	}
}

void	print_error(t_data *parsing)
{
	t_token	*token;

	*(parsing->return_value) = 2;
	token = go_through_list(parsing->token_list, parsing->i);
	ft_putstr_fd("bash: syntax error near unexpected token '", 2);
	ft_putstr_fd(token->str, 2);
	ft_putstr_fd("'\n", 2);
}
