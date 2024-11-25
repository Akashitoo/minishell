/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:48:29 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/04 16:52:15 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	val_exit_last_cmd(t_word_exp *word_ext)
{
	word_ext->var_name = malloc(2 * sizeof(char));
	if (!word_ext->var_name)
		return (0);
	word_ext->var_name[0] = '?';
	word_ext->var_name[1] = '\0';
	word_ext->var_content = ft_itoa(word_ext->exit_status_last_cmd);
	if (!word_ext->var_content)
		return (0);
	get_size_new_str(word_ext);
	word_ext->new_word = (char *) malloc(sizeof(char)
			*(word_ext->size_new_word + 1));
	if (!word_ext->new_word)
		return (free(word_ext->var_name), 0);
	word_ext->new_word[word_ext->size_new_word] = '\0';
	create_new_word(word_ext);
	free(word_ext->var_name);
	free(word_ext->var_content);
	return (2);
}

int	var_extension2(t_word_exp *word_ext, int i)
{
	i++;
	if (!word_ext->word[i])
		return (3);
	else if (word_ext->word[i] == '?')
		return (val_exit_last_cmd(word_ext));
	else if ((word_ext->word[i] > '9' || word_ext->word[i] < '0')
		&& !is_char_name(word_ext->word[i]))
		return (word_ext->sto_ignore++, 2);
	else
	{
		if (!get_value(word_ext, i))
			return (0);
		return (2);
	}
}

int	var_extension(t_word_exp *word_ext)
{
	int		i;

	i = 0;
	while (word_ext->word[i])
	{
		if (word_ext->word[i] == '\'')
			word_ext->quote *= -1;
		if (word_ext->word[i] == '$' && word_ext->sseen == word_ext->sto_ignore
			&& word_ext->quote == 1)
			return (var_extension2(word_ext, i));
		else if (word_ext->word[i] == '$')
		{
			i++;
			word_ext->sseen++;
			if (!word_ext->word[i])
				return (3);
			i--;
		}
		i++;
	}
	return (3);
}
