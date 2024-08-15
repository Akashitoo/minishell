/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:48:29 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/17 13:00:48 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void f(unsigned int i, char *c)
{
	c[i] = 'a';
}
#include <stdio.h>
int main ()
{
	char str[] = "";

	ft_striteri(str, f);
	printf("=>%s<=", str);
	return 0;
}*/