/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:14:50 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/02 16:22:27 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H



# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

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
	int		fd;
	struct s_token	*next;
} t_token;

typedef struct s_data
{
	int		i;
	int		flag;
	int		is_last_word;
	int		nb_tokens;
	int		last_tok;
	int		is_last_op;
	int		status;
	int		error;
	char 	*error_string;
	char	*str;
	t_token	*token_list;
} t_data;




//libft
int		ft_strncmp(const char *str1, const char *str2, size_t n) ;
int		ft_putstr_fd(char *s, int fd);
//utils
int		is_blank(char c);
int		is_op(char c);
int		can_op_match(t_data *parsing);
void	ft_lstadd_tok(t_data *parsing, t_token *new_token);
void	print_tokens(t_token *token_list);
void 	print_parsing(t_data *parsing);
//create_token
int		create_token(t_data *parsing);
//free
void	freetokens(t_token *token_list);
//tokenizer
int		tokenizer(t_data *parsing);
//lexing_parsing
void	lexing_init(t_data *parsing, char *str);
//token_quoting
int		token_quoting(t_data *parsing);

#endif