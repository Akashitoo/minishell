/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:41:17 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/02 15:40:01 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_blank(char c)
{
		return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r');	
}

int	is_op(char c)
{
	return (c == '<' || c == '>' || c == '|');
}

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
void	ft_lstadd_tok(t_data *parsing, t_token *new_token)
{
	t_token	*temp;
	//printf("appel de add_token\n");
	temp = parsing->token_list;
	if (parsing->token_list == NULL)
		parsing->token_list = new_token;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_token;
	}
	//printf("fin de l'appel de add_token\n");
}
void	print_tokens(t_token *token_list)
{
	t_token *temp;
	int i;

	temp = token_list;
	i = 0;
	while (temp)
	{
		printf("TOKEN NUM %d   ", i);
		printf("str->{%s}  $$  type->{%d}\n", temp->str, temp->type);
		temp = temp->next;
		i++;
	}
	printf("le nombre totale de tokens :%d\n", i);
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
void print_parsing(t_data *parsing)
{
	printf("##########appel de print parsing !!####################\n");
	printf("valeur de i = %d\n",parsing->i);
	printf("valeur de flag = %d\n",parsing->flag);
	printf("valeur de is_last_word = %d\n",parsing->is_last_word);
	printf("valeur de nb_tokens = %d\n",parsing->nb_tokens);
	printf("valeur de last_tok = %d\n",parsing->last_tok);
	printf("valeur de is_last_op = %d\n",parsing->is_last_op);
	printf("valeur de status = %d\n",parsing->status);
	printf("#############fin de print parsing#######################\n");

}