/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:57:39 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/09 16:36:19 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(fd, s + i, 1);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
/*#include <stdio.h>
#include <fcntl.h>
int main ()
{
	int	fd;

	fd = open("/home/atrabut/c/Libft/libft.a/prout",O_WRONLY);
	ft_putendl_fd("ceci est un test", fd);
	printf("%d \n",fd);
	
	return 0;
}*/