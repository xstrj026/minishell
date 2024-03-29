#include "../../include/minishell.h"

void	ft_unset(t_env **env_var, t_env **node)
{
	t_env	*env;
	t_env	*new_node;

	new_node = *node;
	env = *env_var;
	while (env)
	{
		if (ft_strcmp2(env->key, new_node->key) == 0)
		{
			free(env->value);
			env->value = new_node->value;
			free(new_node->key);
			if (new_node->next != NULL)
				free(new_node->next);
			free(new_node);
			return (true);
		}
		env = env->next;
	}
	return (false);
}