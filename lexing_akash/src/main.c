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
t_token *parsing_extended(char *argv)
{
	t_data 	parsing;

	lexing_init(&parsing, argv);
	if (!tokenizer(&parsing))
		return (freetokens(parsing.token_list), NULL);
	if (ft_parsing (&parsing) == 0)
		return (freetokens(parsing.token_list), NULL);
	//print_tokens(parsing.token_list);
	if (!ft_word_expansion(&parsing))
		return (freetokens(parsing.token_list), NULL);
	if (!redirection(&parsing))
		return (freetokens(parsing.token_list), NULL);
	//print_tokens(parsing.token_list);
	return (parsing.token_list);
}


// int main() {
//     char *path = getenv("USER");
//     if (path != NULL) {
//         printf("La valeur de PATH est : %s\n", path);
//     } else {
//         printf("La variable PATH n'est pas définie.\n");
//     }

//     char *ma_variable = getenv("MA_VARIABLE");
//     if (ma_variable != NULL) {
//         printf("La valeur de MA_VARIABLE est : %s\n", ma_variable);
//     } else {
//         printf("MA_VARIABLE n'est pas définie.\n");
//     }

//     return 0;
// }