/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrabut <atrabut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:14:50 by atrabut           #+#    #+#             */
/*   Updated: 2024/08/26 15:21:20 by atrabut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define UNDEFINED 0
# define WORD  1
# define INPUT 2
# define OUTPUT 3
# define HERE_DOC 4
# define APPEND 5 
# define PIPE 6
# define END 7
# define HD_CORRUPTED 8

typedef struct s_token
{
	char	*str;
	int		type;
	int		fd;
	struct s_token	*next;
} t_token;
/*
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;*/

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

typedef struct d_word_exp
{
	char	*word;
	char	*var_name;
	char	*var_content;
	int		$to_ignore;
	int		$seen;
	int		flag;
	int		size_word;
	int		size_var_content;
	int		size_var_name;
	int		size_new_word;
	char	*new_word;
	int		quote;
} t_word_exp;

// environ

typedef struct s_cmd
{
	char	**cmd;
	struct	s_cmd	*next;
}	t_cmd;


typedef struct s_env
{
	char *str;
	struct s_env *next;
}	t_env;

t_env   *new_var(char *str);
void    add_back_env(t_env *env, t_env *var);

// builtins 
void	shell_echo(t_token *tokens_list);
void	shell_cd(t_token *tokens_list);
void	shell_pwd(void);
void	shell_env(t_env *env);
void	shell_export(t_env *env, t_token *tokens_list);
void	shell_unset(t_env **env, t_token *tokens_list);

// command

t_cmd	*new_cmd(char **tab);
void	add_back_cmd_list(t_cmd *cmd_list, t_cmd *cmd);
char	**create_cmd_tab(t_token *first_word);
void	free_cmd_list(t_cmd *cmd_list);

// environ

t_env	*new_var(char *str);
void	add_back_env(t_env *env, t_env *var);
t_env	*create_env(char **tab);
void	free_environ(t_env *environ);

// exec pipe

typedef struct s_pipex {
	int		infile;
	int		outfile;
	int		current[2];
	//char	**argv;
	char	**args;
	char	**args2;
	char	**envp;
	int		previous;
	t_cmd	*cmd_list;
}			t_pipex;

void	init_var(t_pipex *pipex, int infile, int outfile, t_cmd *cmd_list, t_env *environ);
void	check_files(t_pipex *pipex, char **argv);
void	check_args(t_pipex *pipex);
void	free_tab(char **tab);
char	*get_path(char *cmd, t_pipex *pipex, int last_cmd);
void	free_close(t_pipex *pipex);
void	error_file_exit(t_pipex *pipex, char *file, int status);
void	error_cmd_exit(t_pipex *pipex, char *cmd, int status);
char	*get_path2(char *cmd, t_pipex *pipex, int last_cmd);
void	pipex(int infile, int outfile, t_cmd *cmd_list, t_env *environ);

//include
//libft
int		ft_strncmp(const char *str1, const char *str2, size_t n) ;
//int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

//get next line
char	*get_next_line(int fd);
int		remplst(t_list **lst, int fd);
t_list	*clearnext(t_list *lst, int *i);
char	*rempres(t_list **lst, char *res);
char	*get_res(t_list **lst);
int		lineinlst(t_list *lst);
int		firstline(t_list *lst);
//void	ft_lstadd_back(t_list **lst, t_list *new, int i);
t_list	*clearfirst(t_list *lst);
int		clearall(t_list *lst);

//src
//utils
int			can_op_match(t_data *parsing);
void		ft_lstadd_tok(t_token **parsing, t_token *new_token);
t_token*	go_through_list(t_token *list, int n);
void		tokenizer3_bis(t_data *parsing);
//print
void		print_tokens(t_token *token_list);
void 		print_parsing(t_data *parsing);
void		print_word_ext(t_word_exp *word_exp);
//is_what
int			is_blank(char c);
int			is_op(char c);


//word_expansion
int		get_value(t_word_exp *word_ext, int i);
int 	ft_word_expansion(t_data *parsing);
int		var_extension(t_word_exp *word_ext);
void	create_new_word(t_word_exp *word_ext);
int		is_char_name(char c);


//redirections
int	redirection(t_data *parsing);

//free
void	freetokens(t_token *token_list);

//lexing
//create_token
int		create_token(t_data *parsing);
//tokenizer
int		tokenizer(t_data *parsing);
//token_quoting
int		token_quoting(t_data *parsing);


//parsing

t_token *parsing_extended(char *argv);
//here_doc
int		here_doc(t_data *parsing);
char	*here_doc2(char *limiter);
//parsing
int 	ft_parsing(t_data *parsing);



//lexing_parsing
void	lexing_init(t_data *parsing, char *str);


#endif