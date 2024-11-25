/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalasub <abalasub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:05:53 by abalasub          #+#    #+#             */
/*   Updated: 2024/09/12 18:24:59 by abalasub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	*environ;

	environ = create_env(envp);
	signal_init_basic();
	disable_ctrl_backslash_display();
	minishell(&environ, 0);
	free_environ(environ);
	rl_clear_history();
	(void)argc;
	(void)argv;
}
