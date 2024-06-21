/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:06:48 by abalasub          #+#    #+#             */
/*   Updated: 2024/06/20 13:18:00 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include "libft/libft.h"

# define UNDEFINED 0
# define WORD  1
# define INPUT 2
# define OUTPUT 3
# define HERE_DOC 4
# define APPEND 5 
# define PIPE 6
# define END 7

typedef struct s_token
{
	char	*str;
	int		type;
	struct s_token	*next;
} t_token;

typedef struct s_env
{
	char *str;
	struct s_env *next;
}	t_env;

t_env   *new_var(char *str);
void    add_back_env(t_env *env, t_env *var);

void	shell_echo(t_token *tokens_list);
void	shell_cd(t_token *tokens_list);
void	shell_pwd(void);
void	shell_env(t_env *env);
void	shell_export(t_env *env, t_token *tokens_list);
void	shell_unset(t_env **env, t_token *tokens_list);

#endif
