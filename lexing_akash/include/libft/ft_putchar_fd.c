/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:44:46 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/09 16:36:20 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
/*#include <stdio.h>
#include <fcntl.h>
int main ()
{
	int	fd;

	fd = open("/home/atrabut/c/Libft/libft.a/prout",O_WRONLY);
	ft_putchar_fd('u', fd);
	printf("%d \n",fd);
	
	return 0;
}*/
