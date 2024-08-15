/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:31:16 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/15 17:46:35 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
#include <string.h>
#include <stdio.h>
int main ()
{
	char *str = "";
	printf("ma fonction que j'ai fait: %ld\n",ft_strlen(str));
	printf("La fonction de base : %ld\n",strlen(str));
	return 0;
}*/