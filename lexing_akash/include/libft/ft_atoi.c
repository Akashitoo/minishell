/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:15:47 by atrabut           #+#    #+#             */
/*   Updated: 2024/06/03 18:37:08 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	res = 0;
	neg = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * neg);
}
// #include <stdlib.h>
// #include <stdio.h>
// int main ()
// {
// 	char *str = "\t\v\f\r\n \f-06050";
// 	printf("Voici le resultat de ma fonction :  %d \n",ft_atoi(str));
// 	printf("Le resultat de la fonction de base: %d \n",atoi(str));
// 	printf("%s",str);
// 	return 0;
// }