/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:25:19 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/26 14:29:21 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
void print_word_ext(t_word_exp *word_exp)
{
	printf("############appel de print word_exp#######################\n");
	printf("valeur du word %s\n", word_exp->word);
	printf("valeur de new_word %s\n", word_exp->new_word);
	printf("valeur de var_name %s\n", word_exp->var_name);
	printf("valeur de var content %s\n", word_exp->var_content);
	printf("valeur de $to_ignore %d\n", word_exp->$to_ignore);
	printf("valeur de $seen %d\n", word_exp->$seen);
	printf("valeur de flag %d\n", word_exp->flag);
	printf("valeur de size_word %d\n", word_exp->size_word);
	printf("valeur de size_var_content %d\n", word_exp->size_var_content);
	printf("valeur de size_var_name %d\n", word_exp->size_var_name);
	printf("valeur de size_new_word %d\n", word_exp->size_new_word);
	printf("######################fin de print wor_ext##############\n");
}