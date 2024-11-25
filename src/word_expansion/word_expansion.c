/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:10:23 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/10 23:09:48 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_word_exp(t_word_exp *word_ext)
{
	word_ext->var_name = NULL;
	word_ext->var_content = NULL;
	word_ext->word = NULL;
	word_ext->new_word = NULL;
	word_ext->sseen = 0;
	word_ext->sto_ignore = 0;
	word_ext->flag = 1;
	word_ext->size_new_word = 0;
	word_ext->size_var_content = 0;
	word_ext->size_var_name = 0;
	word_ext->size_new_word = 0;
	word_ext->quote = 1;
}

void	small_init_word_exp(t_word_exp *word_ext)
{
	if (word_ext->new_word)
	{
		free(word_ext->word);
		word_ext->word = word_ext->new_word;
	}
	word_ext->new_word = NULL;
	word_ext->var_name = NULL;
	word_ext->var_content = NULL;
	word_ext->size_word = 0;
	word_ext->size_new_word = 0;
	word_ext->size_var_name = 0;
	word_ext->size_var_content = 0;
}

void	print_word_ext(t_word_exp *word_exp)
{
	printf("############appel de print word_exp#######################\n");
	printf("valeur du word %s\n", word_exp->word);
	printf("valeur de new_word %s\n", word_exp->new_word);
	printf("valeur de var_name %s\n", word_exp->var_name);
	printf("valeur de var content %s\n", word_exp->var_content);
	printf("valeur de $to_ignore %d\n", word_exp->sto_ignore);
	printf("valeur de $seen %d\n", word_exp->sseen);
	printf("valeur de flag %d\n", word_exp->flag);
	printf("valeur de size_word %d\n", word_exp->size_word);
	printf("valeur de size_var_content %d\n", word_exp->size_var_content);
	printf("valeur de size_var_name %d\n", word_exp->size_var_name);
	printf("valeur de size_new_word %d\n", word_exp->size_new_word);
	printf("######################fin de print wor_ext##############\n");
}

int	one_word_extension(char **str, int *val_exit_last_cmd, t_env *environ)
{
	t_word_exp	word_ext;

	init_word_exp(&word_ext);
	word_ext.environ = environ;
	word_ext.exit_status_last_cmd = *val_exit_last_cmd;
	word_ext.word = *str;
	word_ext.size_word = ft_strlen(*str);
	while (word_ext.flag == 1 || word_ext.flag == 2)
	{
		word_ext.flag = var_extension(&word_ext);
		if (!word_ext.flag)
			return (0);
		if (word_ext.flag == 2)
			small_init_word_exp(&word_ext);
		word_ext.sseen = 0;
	}
	*str = word_ext.word;
	return (1);
}

int	ft_word_expansion(t_data *parsing, t_env *environ)
{
	t_token	*temp;

	temp = parsing->token_list;
	while (temp)
	{
		if (temp->type == WORD)
		{
			if (!one_word_extension(&temp->str, parsing->return_value, environ))
			{
				parsing->error_fatal = 1;
				return (0);
			}
			if (!quote_gone(&temp->str))
			{
				parsing->error_fatal = 1;
				return (0);
			}
		}
		temp = temp->next;
	}
	return (1);
}
