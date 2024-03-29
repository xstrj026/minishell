#include "../../include/minishell.h"



void	printf_exit(char *messege)
{
	printf("%s\n", messege);
	exit(1);
}


char *ft_save_key(char *str, t_env *node)
{
    int i;

    i = 0;
    while (str[i] && (ft_isalpha(str[i]) || str[i] == '_'))
        i++;
    if (str[i] != '=')
    {
		printf("'=' was not filled, value cant be stored");
        free(node->key); // Uvolnění paměti pro node->key
        return (NULL);
    }
    node->key = (char *)ft_calloc((i + 1), sizeof(char));
    i = 0;
    while (str[i] && ft_isalpha(str[i]))
    {
        node->key[i] = str[i];
        i++;
    }
    node->key[i] = '\0';
    return (node->key);
}

int	start_index_of_value(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')//preskocime vsechny znaky ktere uz jsou v key(tj. az po '=')
		i++;
	return (i);
}

bool	sign_equal_is_presented(char *str, int i, t_env **node)
{
	if (str[i] != '=')//kontrola; musi byt za key =
	{
		debug_printf("Attention, export has to work with '=' sign\n");
		free((*node)->key);
		return (false);
	}
	return (true);
}

char	*ft_save_value(char *str, t_env *node)
{
	int	i;
	int	j;
	int	size;

	j = 0;
	i = start_index_of_value(str);
	if (!sign_equal_is_presented(str, i, &node))
		return (NULL);
	i++;//preskocime'='
	j = i;//ulozime si index/zacatek dalsiho retezce
	/* 
	ZDE ŘEŠIT QUOTES "" A ''
	if quotes

	else
	{ */
		while (str[i] && ft_isprint(str[i]))//pocitame kolik znaku je value
		{
			i++;
		}
		size = i - j;
		i = j;
		j = 0;
		node->value = (char *)ft_calloc((size + 2), sizeof(char));
		while (str[i] && ft_isprint(str[i]))
		{
			node->value[j] = str[i];
			i++;
			j++;
		}
	printf("value is : %s\n", node->value);
	return(node->value);
}

void	print_env(t_env *env)
{
	t_env *current;

	if (!DEBUG_MODE)
	{
		return ;
	}
	current = env;
	printf("\n");
	while (current != NULL && DEBUG_MODE)
	{
		printf(RED"Key: %s, Value: %s\n"RST, current->key, current->value);
		current = current->next;
	}
}

bool	key_is_already_in_env(t_env **env_var, t_env **node)
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

void	ft_append_var_node(t_env **env_var, t_env **node_to_apend)
{
	t_env	*current;
	t_env	*node;

	node = *node_to_apend;
	current = *env_var;
	if (*env_var == NULL)
		*env_var = node;
	else if (key_is_already_in_env(env_var, &node))
		printf("ENV UPDATE, THE VALUE WAS CHANGED\n");
	else if (current)
	{
		while (current)
		{
			if (current->next == NULL)
			{
				current->next = node;
				break;
			}
			current = current->next;
		}
	}
	print_env(*env_var);
	return ;
}


void	ft_export(t_list *list, t_env **env_var)
{
	char	*str;
	t_env	*node;

	str = list->cmd_text;
	node = (t_env *)ft_calloc(1, sizeof (t_env));
	if (ft_save_key(str, node) == NULL)
	{
		free(node);
		return;
	}
	//node->next = NULL;
	//kontrola
	if ((ft_save_value(str, node)) == NULL)
	{
		free(node->key);
		free(node);
		return ;
	}
	node->next = NULL;
	ft_append_var_node(env_var, &node);
	return ;
}

