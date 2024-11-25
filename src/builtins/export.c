/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <abalasub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:45:12 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/12 18:54:59 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_equal_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

int	is_variable_valid(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '_' && (str[0] < 'a' || str[0] > 'z')
		&& (str[0] < 'A' || str[0] > 'Z'))
	{
		ft_putstr_fd("export: '", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (0);
	}
	while (str[i] && str[i] != '=')
	{
		if (!is_char_name(str[i]))
		{
			ft_putstr_fd("export: '", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	shell_export_aux(char *dest, char *src, t_env **current)
{
	ft_memcpy(dest, src, (size_t)ft_strlen(src) + 1);
	(*current)->str = dest;
	(*current)->is_mine = 1;
	return (0);
}
