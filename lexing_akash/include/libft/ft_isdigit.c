/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:40:28 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/09 16:36:25 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (2048);
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
		printf("ma fonction que j'ai fait: %d\n",ft_isdigit(i));
		printf("La fonction de base : %d\n",isdigit(i));
		if (isdigit(i)!= ft_isdigit(i))
			printf("3333333333333####################################\n");
		i++;
	}
	return 0;
}*/
