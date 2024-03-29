#include "../../include/minishell.h"

void	ft_print_env(t_env *env)
{
	t_env *current = env;
	while (current != NULL) 
	{
		printf(RED"%s=%s\n"RST, current->key, current->value);
		current = current->next;
	}
}