/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:39:15 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/16 17:02:27 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	remplst(t_list **lst, int fd)
{
	t_list	*new;
	int		i;

	i = 0;
	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (clearall(*lst));
	new->content = (char *)malloc ((BUFFER_SIZE + 1));
	if (!new->content)
	{
		free(new);
		return (clearall(*lst));
	}
	new->next = NULL;
	i = read(fd, new->content, BUFFER_SIZE);
	if (i <= 0)
	{
		free(new->content);
		free(new);
		if (i < 0)
			clearall(*lst);
	}
	else if (i > 0)
		ft_lstadd_back(lst, new, i);
	return (i);
}

char	*coupe(char *str, int i, t_list **lst)
{
	int	count;

	count = 0;
	if (!str[i])
	{
		*lst = clearfirst(*lst);
		return (NULL);
	}
	while (str[i])
	{
		str[count] = str[i];
		i++;
		count++;
	}
	str[count] = '\0';
	return (str);
}

char	*rempres(t_list **lst, char *res)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (*lst)
	{
		while (((*lst)->content)[i])
		{
			res[count] = ((*lst)->content)[i];
			if (res[count] == '\n')
			{
				coupe((*lst)->content, i + 1, lst);
				res[count + 1] = '\0';
				return (res);
			}
			i++;
			count++;
		}
		i = 0;
		*lst = clearfirst(*lst);
	}
	res[count] = '\0';
	return (res);
}

char	*get_res(t_list **lst)
{
	char	*res;
	int		temp;

	temp = firstline(*lst);
	if (temp == 1)
		return (NULL);
	res = (char *) malloc((temp) * sizeof(char));
	res = rempres(lst, res);
	return (res);
}

char	*get_next_line(int fd)
{
	int				flag;
	static t_list	*lst = NULL;

	if (BUFFER_SIZE < 1)
		return (NULL);
	flag = BUFFER_SIZE;
	//printf("appel de gnl\n");
	while (!lineinlst(lst) && flag == BUFFER_SIZE)
	{
		flag = remplst(&lst, fd);
		if (flag < 0)
			return (NULL);
	}
	return (get_res(&lst));
}
// #include <stdio.h>
// int main ()
// {
// 	char *buf;
// 	int fd = open("tester.txt", O_RDONLY); 
// 	int i = 1;
// 	int secu = 3;
// 	printf("test\n");
// 	while(i > 0 && secu)
// 	{
// 		buf  = get_next_line(fd);
// 		i  = printf("%s",buf);
// 		free(buf);
// 		secu--;
// 	}
// 	// printf("%zd", read(fd,buf,10));
// 	// printf("%zd", read(fd,buf,10));
// 	return (0);
// }