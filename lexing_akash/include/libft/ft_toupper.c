/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:32:58 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/09 16:36:09 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c <= 'z' && c >= 'a')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int main ()
{
	printf("Voici ma fct : %d \n", ft_toupper(10));
	printf("pAS MA FCT fct : %d \n", toupper(10));
	return 0;
}*/
