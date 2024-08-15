/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quoting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:18:21 by atrabut           #+#    #+#             */
/*   Updated: 2024/06/18 19:20:23 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//quoting est une fonction qui va jusqu'au bout du quote en renvoi le contenue sous la forme d'un
//token qui contient toute la chaine de caractere en cas d'erreur elle va liberer la memoire en renvoyer NULL
//la fonction tokenisation est cense quitter le programme par lui meme 
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
			return (freetokens(parsing->token_list), 0);
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
			return (freetokens(parsing->token_list), 0);
		}
	}
	parsing->flag = 1;
	return (2);
}
