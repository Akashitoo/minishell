/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <abalasub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:14:50 by atrabut           #+#    #+#             */
/*   Updated: 2024/09/12 18:27:14 by abalasub         ###   ########.fr       */
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
# include <sys/stat.h>
# include <signal.h>
# include <termios.h>
# include <bits/termios-c_lflag.h>
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
	char			*str;
	int				type;
	int				fd;
	struct s_token	*next;
}	t_token;

typedef struct s_env
{
	char			*str;
	struct s_env	*next;
	int				is_mine;
}	t_env;

typedef struct s_data
{
	int		*return_value;
	int		i;
	int		flag;
	int		is_last_word;
	int		nb_tokens;
	int		last_tok;
	int		is_last_op;
	int		status;
	int		error_fatal;
	char	*error_string;
	char	*str;
	t_token	*token_list;
}	t_data;

typedef struct d_word_exp
{
	char	*word;
	char	*var_name;
	char	*var_content;
	int		sto_ignore;
	int		sseen;
	int		flag;
	int		size_word;
	int		size_var_content;
	int		size_var_name;
	int		size_new_word;
	char	*new_word;
	int		quote;
	t_env	*environ;
	int		exit_status_last_cmd;
}	t_word_exp;

typedef struct s_cmd
{
	char			**cmd;
	int				infile_fd;
	char			*infile_str;
	int				outfile_fd;
	char			*outfile_str;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_exec_line
{
	t_token	*tokens_list;
	t_token	*current_token;
	t_token	*memo;
	t_cmd	*cmd_list;
	int		infile;
	int		outfile;
	char	*infile_str;
	char	*outfile_str;

}t_exec_line;

typedef struct s_export
{
	char	*dest;
	char	*src;
	int		is_error;
	t_env	**env;
}	t_export;

// main
//exec_line
void	exec_line(t_token *token_list, t_env *environ, int *return_value);
void	minishell(t_env **environ, int return_value);
void	add_back_env(t_env *env, t_env *var);
t_env	*new_var(char *str, int is_mine);

// builtins 
int		get_write_fd(t_token *tokens_list);
void	shell_echo(t_token *tokens_list, int *return_value, int write_fd);
void	shell_cd(t_token *tokens_list, int *return_value);
void	shell_pwd(int *return_value, int write_fd);
void	shell_env(t_env *env, int *return_value,
			int write_fd, t_token *tokens_list);
//export
int		is_equal_sign(char *str);
int		is_variable_valid(char *str);
int		shell_export_aux(char *dest, char *src, t_env **current);
int		shell_export(t_env **env, t_token *tokens_list);
void	shell_unset(t_env **env, t_token *tokens_list, int *return_value);
void	shell_exit(t_token *tokens_list, int *return_value, t_env *environ);
//check_builtins
void	check_builtins(t_env **environ, t_token **tokens_list,
			int *return_value);
// command

t_cmd	*new_cmd(char **tab, t_exec_line *structure);
void	add_back_cmd_list(t_cmd **cmd_list, t_cmd *cmd);
char	**create_cmd_tab(t_exec_line *structure);
void	free_cmd_list(t_cmd *cmd_list);
void	print_cmd_list(t_cmd *cmd_list);

// environ

t_env	*create_env(char **tab);
void	add_back_env(t_env *env, t_env *var);
void	free_environ(t_env *environ);

// exec pipe

typedef struct s_pipex {
	int		infile;
	int		outfile;
	int		current[2];
	t_cmd	*args;
	t_cmd	*args2;
	char	**envp;
	int		previous;
	t_cmd	*cmd_list;
	char	*infile_str;
	char	*outfile_str;
	t_token	*tokens_list;
	t_env	*environ;
}			t_pipex;

void	init_var(t_pipex *pipex, t_exec_line *structure, t_env *environ);
void	check_files(t_pipex *pipex, char **argv);
void	check_args(t_pipex *pipex);
void	free_tab(char **tab);
char	*get_path(char *cmd, t_pipex *pipex);
void	free_close(t_pipex *pipex, int return_value);
int		is_directory(const char *path);
void	error_file_exit(t_pipex *pipex, char *file);
void	error_cmd_exit(t_pipex *pipex, char *cmd);
char	*get_path2(char *cmd, t_pipex *pipex, int last_cmd);
int		size_of_cmd_list(t_cmd	*cmd_list);
int		wait_all_process(t_cmd *cmd_list, int *status);
void	no_command(t_pipex *pipex, int *return_value);
void	close_all_fd(t_token *token_list);
void	pipex(t_exec_line *structure, t_env *environ, int *return_value);

// builtins fork version

void	shell_env_fork(t_pipex *pipex, char **cmd_options);
void	shell_pwd_fork(t_pipex *pipex);
void	shell_echo_fork(char **cmd, t_pipex *pipex);
void	shell_cd_fork(char **cmd, t_pipex *pipex);
void	shell_export_fork(char	**cmd, t_pipex *pipex);
void	shell_exit_fork(char **cmd, t_pipex *pipex);
//include
//libft
int		ft_strncmp(const char *str1, const char *str2, size_t n);
//int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
char	*ft_itoa2(int *n);

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
void	close_all(int exit_value, t_pipex *pipex);
int		can_op_match(t_data *parsing);
void	ft_lstadd_tok(t_token **parsing, t_token *new_token);
t_token	*go_through_list(t_token *list, int n);
void	tokenizer3_bis(t_data *parsing);
//print
void	print_tokens(t_token *token_list);
void	print_parsing(t_data *parsing);
void	print_word_ext(t_word_exp *word_exp);
//is_what
int		is_blank(char c);
int		is_op(char c);

//signal
void	handle_signal_readline(int sig);
void	handle_signal_here_doc(int sig);
void	handle_signal_basic(int sig);
void	signal_init_here_doc(void);
void	signal_init_readline(void);
void	signal_init_basic(void);
void	disable_ctrl_backslash_display(void);

//word_expansion
//word_expansion.c
void	get_size_new_str(t_word_exp *word_ext);
int		get_value(t_word_exp *word_ext, int i);
int		ft_word_expansion(t_data *parsing, t_env *environ);
int		var_extension(t_word_exp *word_ext);
void	create_new_word(t_word_exp *word_ext);
int		is_char_name(char c);
//quoite_gone.c
int		quote_gone(char **str);
//my_getenv.c
char	*my_getenv(t_word_exp *word_exp);

//redirections
void	redirection(t_data *parsing);

//free
void	freetokens(t_token *token_list);
void	freetokens2(t_token *token_list);

//lexing
//create_token
int		create_token(t_data *parsing);
//tokenizer
int		tokenizer(t_data *parsing);
//token_quoting
int		token_quoting(t_data *parsing);

//parsing

t_token	*parsing_extended(char *argv, int *val_exit_last_cmd, t_env *environ);
//here_doc
char	*here_doc(char *limiter);
//here_doc2
int		list_size_str(t_token *list);
char	*list_to_str(t_token *list);
//parsing
int		ft_parsing(t_data *parsing);
//print_error
void	print_error_next(t_data *parsing);
void	print_error(t_data *parsing);

//lexing_parsing
void	lexing_init(t_data *parsing, char *str);

#endif