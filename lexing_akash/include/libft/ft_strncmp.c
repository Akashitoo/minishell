/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:57:34 by atrabut           #+#    #+#             */
/*   Updated: 2024/06/14 11:42:04 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((str2[i] || str1[i]) && i < n - 1)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
/*#include <stdio.h>
int main (){
	char *str = "def";
	char *str1 = "\375xx";
	printf("Verification de ma fonction;) %d\n", ft_strncmp(str,str1,5));
	printf("test %d\n", 'd' - '\375');
	return 0;
}*/