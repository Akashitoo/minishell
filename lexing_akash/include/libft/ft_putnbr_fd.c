/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:10:18 by atrabut           #+#    #+#             */
/*   Updated: 2023/11/16 16:49:22 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}

/*#include <stdio.h>
#include <fcntl.h>
int main ()
{
	int	fd;

	fd = open("prout.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(-2147483648, fd);
	printf("%d \n",fd);
	return 0;
}*/