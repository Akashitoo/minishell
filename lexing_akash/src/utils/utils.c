/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:41:17 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/26 14:29:17 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	can_op_match(t_data *parsing)
{
	char	d;
	char	c;

	c = parsing->str[parsing->i];
	d = parsing->str[parsing->i - 1]; 
	if ((c == '<' && d == '<' ) || (c == '>' && d == '>'))
			return (1);
	return (0);
}
void	ft_lstadd_tok(t_token **token_list, t_token *new_token)
{
	t_token	*temp;
	//printf("appel de add_token\n");
	temp = *token_list;
	if (*token_list == NULL)
		*token_list = new_token;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_token;
	}
	//print_tokens(token_list);
	//printf("fin de l'appel de add_token\n");
}



t_token*	go_through_list(t_token *list, int n)
{
	t_token *temp;

	temp = list;
	while(n > 0 && temp)
	{
		n--;
		temp = temp->next;	
	}
	return (temp);
}

void	tokenizer3_bis(t_data *parsing)
{
	parsing->flag = 1;
	parsing->is_last_word = 2;	
}

