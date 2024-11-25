/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:40:54 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/15 19:40:27 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		remplst(t_list **lst, int fd);
t_list	*clearnext(t_list *lst, int *i);
char	*rempres(t_list **lst, char *res);
char	*get_res(t_list **lst);
int		lineinlst(t_list *lst);
int		firstline(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new, int i);
t_list	*clearfirst(t_list *lst);
int		clearall(t_list *lst);
#endif