#include "../../include/minishell.h"

void	ft_free_env_key_value(t_env **env_var)
{
	t_env	*env;

	env = *env_var;
	debug_printf("\nfree env: ");
	debug_printf(env->key);
	if (env->key)
		free(env->key);
	debug_printf(env->value);
	if (env->value)
	{
		free(env->value);
	}
	return ;
}

void	change_list_free_node(t_env **env, t_env **last_env)
{
	ft_free_env_key_value(env);
	(*last_env)->next = (*env)->next;
	free(*env);
}

void	ft_unset(t_env **env_var, t_list *list)
{
	t_env	*env;
	t_env	*last_env;
	char	*command_text;

	last_env = NULL;
	command_text = list->cmd_text;
	env = *env_var;
	while (env)
	{
		print_env(env);
		if (ft_strcmp2(env->key, command_text) == 0)
		{
			if (ft_strcmp2(env->key, (*env_var)->key) == 0)
			{
				ft_free_env_key_value(&env);
				(*env_var) = env->next;
				free(env);
				return ;
			}
			change_list_free_node(&env, &last_env);
			return ;
		}
		last_env = env;
		env = env->next;
	}
	return ;
}