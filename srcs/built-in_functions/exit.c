#include "../../include/minishell.h"

void	ft_exit(t_list **list, t_token *operator_tok, t_array array, int exit_number)
{
	printf("\nft_exit: Free memory \nCLosing minishell\n");
	ft_free_all(list, operator_tok, array);
	exit(exit_number);
}