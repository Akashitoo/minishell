/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:10:23 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/26 14:29:56 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*on se donne a fond demain*/
/*ici l'idee est de juste degager le nom de la variable sans rien prendre de plus*/


void init_word_exp(t_word_exp *word_ext)
{
	word_ext->var_name = NULL;
	word_ext->var_content = NULL;
	word_ext->word = NULL;
	word_ext->new_word = NULL;
	word_ext->$seen = 0;
	word_ext->$to_ignore = 0;
	word_ext->flag = 1;
	word_ext->size_new_word = 0;
	word_ext->size_var_content = 0;
	word_ext->size_var_name = 0;
	word_ext->size_new_word = 0;
	word_ext->quote = 1;
}

void small_init_word_exp(t_word_exp *word_ext)
{
	
	if (word_ext->new_word)
	{
		free(word_ext->word);
		word_ext->word = word_ext->new_word;
	}
	word_ext->var_name = NULL;
	word_ext->var_content = NULL;
	word_ext->size_word = 0;
	word_ext->size_new_word = 0;
	word_ext->size_var_name = 0;
	word_ext->size_var_content = 0;
}

/*gerer les leaks de memoires + le cas " dns le here_doc +le cas quote (un nouveau type de word dans lequelle pas d'extension)"*/
int one_word_extension(char **str)
{
	t_word_exp word_ext;

	init_word_exp(&word_ext);
	word_ext.word = *str;
	word_ext.size_word = ft_strlen(*str);
	
	while (word_ext.flag == 1 || word_ext.flag == 2)
	{
		//print_word_ext(&word_ext);
		word_ext.flag = var_extension(&word_ext);
		// printf("val de $to_ignore : %d\n",word_ext.$to_ignore);
		// printf("val de $seen        %d\n", word_ext.$to_ignore);
		if (!word_ext.flag)
			return (0);
		if (word_ext.flag == 2)
			small_init_word_exp(&word_ext);
		word_ext.$seen = 0;
	}
	*str = word_ext.word;
	return (1);
}

int ft_word_expansion(t_data *parsing)
{
	t_token *temp;
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	temp = parsing->token_list;
	while (temp)
	{
		//ft_putstr_fd(temp->str, 1);
		if (temp->type == WORD)
			one_word_extension(&temp->str);
		temp = temp->next;
	}
	return (1);
}
