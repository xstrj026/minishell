#include "../../include/minishell.h"

void	free_all_env(t_env **env_var)
{
	t_env	*tmp;
	t_env	*next;

	msg_error("env $ cleaning");
	tmp = *env_var;
	while (tmp != NULL)
	{
		free(tmp->key);
		free(tmp->value);
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void	ft_exit(t_list **list, t_token *operator_tok, t_array **m_array, int exit_number, t_env **env_var)
{
	t_array	*array;

	array = *m_array;
	msg_error("\nft_exit: Free memory \nCLosing minishell\n");
	ft_free_all(list, operator_tok, &array);
	free_all_env(env_var);
	exit(exit_number);
}