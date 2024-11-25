/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_extended.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:57:57 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/12 11:11:50 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	lexing_init(t_data *parsing, char *str)
{
	parsing->error_fatal = 0;
	parsing->i = 0;
	parsing->is_last_word = 0;
	parsing->is_last_op = 0;
	parsing->last_tok = 0;
	parsing->flag = 0;
	parsing->nb_tokens = 0;
	parsing->status = 1;
	parsing->str = str;
	parsing->token_list = NULL;
}

void	init_fds(t_token *token_list)
{
	t_token	*temp;

	temp = token_list;
	while (temp)
	{
		temp->fd = 0;
		temp = temp->next;
	}
}

void	print_parsing(t_data *parsing)
{
	printf("##########appel de print parsing !!####################\n");
	printf("valeur de i = %d\n", parsing->i);
	printf("valeur de flag = %d\n", parsing->flag);
	printf("valeur de is_last_word = %d\n", parsing->is_last_word);
	printf("valeur de nb_tokens = %d\n", parsing->nb_tokens);
	printf("valeur de last_tok = %d\n", parsing->last_tok);
	printf("valeur de is_last_op = %d\n", parsing->is_last_op);
	printf("valeur de status = %d\n", parsing->status);
	printf("#############fin de print parsing#######################\n");
}

void	print_tokens(t_token *token_list)
{
	t_token	*temp;
	int		i;

	temp = token_list;
	i = 0;
	while (temp)
	{
		printf("TOKEN NUM %d   ", i);
		printf("str->{%s}  $$  type->{%d}\n", temp->str, temp->type);
		printf("valeur de fd %d\n", temp->fd);
		temp = temp->next;
		i++;
	}
	printf("le nombre totale de tokens :%d\n", i);
}

t_token	*parsing_extended(char *argv, int *val_exit_last_cmd, t_env *environ)
{
	t_data	parsing;

	lexing_init(&parsing, argv);
	parsing.return_value = val_exit_last_cmd;
	if (!tokenizer(&parsing) && parsing.error_fatal == 0)
		return (freetokens(parsing.token_list), NULL);
	if (!parsing.token_list)
		return (NULL);
	init_fds(parsing.token_list);
	if (!ft_parsing (&parsing) && parsing.error_fatal == 0)
		return (freetokens2(parsing.token_list), NULL);
	if (!ft_word_expansion(&parsing, environ) && parsing.error_fatal == 0)
		return (freetokens2(parsing.token_list), NULL);
	redirection(&parsing);
	if (parsing.error_fatal == 1)
	{
		freetokens2(parsing.token_list);
		*(parsing.return_value) = 1;
		exit(EXIT_FAILURE);
	}
	return (parsing.token_list);
}
