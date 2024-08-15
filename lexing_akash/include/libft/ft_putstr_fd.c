/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:11:58 by atrabut           #+#    #+#             */
/*   Updated: 2024/06/14 15:50:24 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		return (ft_putstr_fd("(null)", 1));
	}
	while (s[i])
	{
		write(fd, s + i, 1);
		i++;
	}
	return (i);
}
/*#include <stdio.h>
#include <fcntl.h>
int main ()
{
	int	fd;

	fd = open("/home/atrabut/c/Libft/libft.a/prout",O_WRONLY);
	ft_putstr_fd("voici leslettres", fd);
	printf("%d \n",fd);
	return 0;
}*/
