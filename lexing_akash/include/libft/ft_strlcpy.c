/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:04:29 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/17 16:43:02 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;

	i = 0;
	lensrc = ft_strlen(src);
	if (size <= 0)
		return (lensrc);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lensrc);
}
/*#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
int main ()
{
    char source[] = "Hello, world!";
    char destination[20];
    char destination2[20];

    size_t result;
    result = strlcpy(destination, source, 5);
    size_t result2;
    result2 = ft_strlcpy(destination2, source, sizeof(destination2));
    // Affiche la destination et la valeur de retour de strlcpy
    printf(" Fonction de base : \n");
    printf("Destination: %s\n", destination);
    printf("Valeur de retour de strlcpy: %zu\n", result);
    printf("#####################################\n");
    printf("Ma fonction : \n");
    printf("Destination: %s\n", destination2);
    printf("Valeur de retour de strlcpy: %zu\n", result2);
    return 0;
}*/