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
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include "../../libft/libft.h"

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

typedef struct s_env
{
	char *str;
	struct s_env *next;
}	t_env;


typedef struct s_cmd
{
	char	**cmd;
	struct	s_cmd	*next;
}	t_cmd;

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

//libft
int		ft_strncmp(const char *str1, const char *str2, size_t n) ;
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

t_env   *new_var(char *str);
void    add_back_env(t_env *env, t_env *var);

void	shell_echo(t_token *tokens_list);
void	shell_cd(t_token *tokens_list);
void	shell_pwd(void);
void	shell_env(t_env *env);
void	shell_export(t_env *env, t_token *tokens_list);
void	shell_unset(t_env **env, t_token *tokens_list);

#endif
