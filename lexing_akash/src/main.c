#include "../include/minishell.h"

void	lexing_init(t_data *parsing, char *str)
{
	parsing->i = 0;
	parsing->is_last_word = 0;
	parsing->is_last_op = 0;
	parsing->last_tok = 0;
	parsing->flag = 0;
	parsing->nb_tokens = 0;
	parsing->status = 1;
	parsing->str = str;
	parsing->token_list = NULL;
	
}
/*
int main (int argc, char **argv)
{
	t_data 	parsing;

	if (argc != 2)
		return (0);
	lexing_init(&parsing, argv[1]);
	//jusqu'ici aucun malloc de fait
	if (!tokenizer(&parsing))
		return (0);
	

	freetokens(parsing.token_list);
	return (1);
}
*/