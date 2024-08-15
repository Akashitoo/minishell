/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:52:12 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/09 16:36:27 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c < '0' || c > '9') && (c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
	{
		return (0);
	}
	return (8);
}
/*
#include <ctype.h>
#include <stdio.h>
int main ()
{
	int i;
	i = 0;
	while(i< 127)
	{ 
		printf("ma fonction que j'ai fait: %d\n",ft_isalnum(i));
		printf("La fonction de base : %d\n",isalnum(i));
		if (isalnum(i)!= ft_isalnum(i))
			printf("3333333333333####################################\n");
		i++;
	}
	return 0;
}*/