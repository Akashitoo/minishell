/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:39:42 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/09 16:36:10 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c <= 'Z' && c >= 'A')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int main ()
{
	printf("Voici ma fct : %d \n", ft_tolower(75));
	printf("pAS MA FCT fct : %d \n", tolower(75));
	return 0;
}*/