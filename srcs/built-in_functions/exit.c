#include "../../include/minishell.h"

void	ft_exit(t_list **list, t_token *operator_tok, t_array array, int exit_number, t_env **env_var)
{
	printf("\nft_exit: Free memory \nCLosing minishell\n");
	ft_free_all(list, operator_tok, array);

	//vycistit pamet
	t_env *tmp = *env_var;
	t_env *next;
	while (tmp != NULL)
	{
		free(tmp->key);
		free(tmp->value);
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	// if(*env_var!=NULL)
	// 	free(*env_var);
	exit(exit_number);
}