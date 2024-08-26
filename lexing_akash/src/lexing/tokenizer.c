/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:02:11 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/26 16:20:32 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int tokenizer1(t_data *parsing)
{
	if (parsing->i > 0)
		parsing->is_last_op = is_op(parsing->str[parsing->i - 1]);
	if (parsing->is_last_op &&  parsing->i - parsing->last_tok > 0)
	{
		// printf("on est sure aque le caactere d'avant st un operateur\n");
		if (can_op_match(parsing))
		{ 
			if (!create_token(parsing))
				return (freetokens(parsing->token_list), 0);
			parsing->status = 2;
		}
		else
		{
			parsing->i--;
			if (!create_token(parsing))
				return (freetokens(parsing->token_list), 0);
			parsing->i++;
			parsing->status = 1;
		}
		parsing->flag = 0;
	}
	if ((parsing->status != 2 && parsing->str[parsing->i] == '\'' ) || parsing->str[parsing->i] == '\"')
		parsing->status = token_quoting(parsing);
	return (parsing->status);
}
int	tokenizer2(t_data *parsing)
{
	if (is_op(parsing->str[parsing->i]))
	{
		if (parsing->flag && !parsing->is_last_op)
		{
			parsing->i--;
			if (!create_token(parsing))
				return (freetokens(parsing->token_list), 0);
			parsing->i++;
		}
		parsing->flag = 1;
		parsing->status = 2;
	}
	else if (parsing->str[parsing->i] == '\n')
	{
		if (parsing->flag)
		{
			parsing->i--;
			if (!create_token(parsing))
				return (freetokens(parsing->token_list), 0);
			parsing->i++;
			parsing->last_tok++;
		}
		parsing->status = 2;
	}
	return (parsing->status);
}
int	tokenizer3(t_data *parsing)
{
 
	if (is_blank(parsing->str[parsing->i]))
	{
		if (parsing->flag)
		{
			parsing->i--;
			if (!create_token(parsing))
				return (freetokens(parsing->token_list), 0);
			parsing->i++;
			parsing->flag = 0;
		}
		else 
			parsing->last_tok++;
	}
	else if (parsing->is_last_word)
		parsing->is_last_word = 2;
	else if (parsing->str[parsing->i] == '#')
	{
		while(parsing->str[parsing->i] != '\n')
			parsing->i++;
	}
	else
		tokenizer3_bis(parsing);
	return (1);
}
int	end_of_input(t_data *parsing)
{
	t_token *new_token;

	if (parsing->flag)
	{
		parsing->i--;
		if (!create_token(parsing))
			return (printf("check\n"), freetokens(parsing->token_list), 0);
	}
	else
	{
		new_token = malloc(sizeof(t_token));
		if (!new_token)
			return (freetokens(parsing->token_list), 0);
		new_token->str = malloc(sizeof(char));
		if (!new_token->str)
			return (free(new_token), freetokens(parsing->token_list), 0);
		new_token->str[0] = '\0';
		new_token->type = END;
		new_token->next = NULL;
		ft_lstadd_tok(&parsing->token_list, new_token);
		}
		
	return (1);
}

//transforme ma chaine de char en un tableau de str...en respectant ces regles 
//https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_03
//afin de s'eviter le sizemal et d'autres pblm on va creer une liste chaine.....qui ontiendra le okens e leur type
//la mission du jour transformr cette foncion en un createur de liste chainee
int	tokenizer(t_data *parsing)
{
	while (parsing->str[parsing->i])
	{
		parsing->status = 1;
		if (!tokenizer1(parsing))
			return (0);
		if (parsing->status == 1)
		{
			if (!tokenizer2(parsing))
				return (0);
		}
		if (parsing->status == 1)
		{
			if (!(tokenizer3(parsing)))
				return (0);
		}
		parsing->i++;
		if (parsing->is_last_word > 0)
			parsing->is_last_word--;
	}
	if (!end_of_input(parsing))
		return (0);
	return (1);
}


