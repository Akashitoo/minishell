/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:09:35 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/09 16:36:26 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int main ()
{
	int i;
	i = 0;
	while(i< 400)
	{ 
		printf("ma fonction que j'ai fait: %d\n",ft_isascii(i));
		printf("La fonction de base : %d\n",isascii(i));
		if (isascii(i)!= ft_isascii(i))
			printf("3333333333333####################################\n");
		i++;
	}
	return 0;
}*/
