/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:20:49 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/09 16:36:24 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c <= 31 || c >= 127)
	{
		return (0);
	}
	return (16384);
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
		printf("ma fonction que j'ai fait: %d\n",ft_isprint(i));
		printf("La fonction de base : %d\n",isprint(i));
		if (isprint(i)!= ft_isprint(i))
			printf("3333333333333####################################\n");
		i++;
	}
	return 0;
}*/
