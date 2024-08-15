/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:56:16 by abalasub          #+#    #+#             */
/*   Updated: 2024/05/31 17:06:49 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct s_data {
	int		infile;
	int		outfile;
	int		current[2];
	char	**argv;
	char	**args;
	char	**args2;
	char	**envp;
	int		previous;
}			t_data;

void	init_var(t_data *pipex, char **argv, char **envp, int argc);
void	check_files(t_data *pipex, char **argv);
void	check_args(t_data *pipex);
void	free_tab(char **tab);
char	*get_path(char *cmd, t_data *pipex, int last_cmd);
void	free_close(t_data *pipex);
void	error_file_exit(t_data *pipex, char *file, int status);
void	error_cmd_exit(t_data *pipex, char *cmd, int status);
char	*get_path2(char *cmd, t_data *pipex, int last_cmd);

#endif
