/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:48:29 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/24 15:42:25 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"


int	var_extension2(t_word_exp *word_ext, int i)
{
	i++;
	if(!word_ext->word[i])
		return (3);
	else if ((word_ext->word[i] > '9' || word_ext->word[i] < '0') &&
			(!is_char_name(word_ext->word[i]) && word_ext->word[i] != '!'))
		return (word_ext->$to_ignore++, 1);
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
	while(word_ext->word[i])
	{
		if (word_ext->word[i] == '\'')
			word_ext->quote *= -1;
		if (word_ext->word[i] == '$' && word_ext->$seen == word_ext->$to_ignore &&
			word_ext->quote == 1)
		{
			return (var_extension2(word_ext, i));
		}
		else if (word_ext->word[i] == '$')
		{
			i++;
			word_ext->$seen++;
			if (!word_ext->word[i])
				return (3);
		}
		i++;
	}
	return (3);
}

