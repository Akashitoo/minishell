/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quoting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:18:21 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/11 00:44:45 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	token_quoting(t_data *parsing)
{
	if (parsing->str[parsing->i] == '\'')
	{
		parsing->i++;
		while (parsing->str[parsing->i] && parsing->str[parsing->i] != '\'')
			parsing->i++;
		if (!parsing->str[parsing->i])
		{
			ft_putstr_fd("unclosed \' (single quote)\n", 2);
			return (0);
		}
	}
	else if (parsing->str[parsing->i] == '\"')
	{
		parsing->i++;
		while (parsing->str[parsing->i] && parsing->str[parsing->i] != '\"')
			parsing->i++;
		if (!parsing->str[parsing->i])
		{
			ft_putstr_fd("unclosed \" (double quote)\n", 2);
			return (0);
		}
	}
	parsing->flag = 1;
	return (2);
}
