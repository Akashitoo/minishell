/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_what.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:27:34 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/04 16:38:52 by atrabut          ###   ########.fr       */
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