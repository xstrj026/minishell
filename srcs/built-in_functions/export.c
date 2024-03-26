#include "../../include/minishell.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (NULL == ret)
	{
		printf("Error: malloc failed");
		exit(1);
	}
	return (ret);
}

void	printf_exit(char *messege)
{
	printf("%s\n", messege);
	exit(1);
}

// void	printf_return(char *messege)
// {
// 	printf("%s\n", messege);
// 	return ;
// }


char	*ft_save_key(char *str, t_env *node)
{
	int	i;

	i = 0;
	while (str[i] && (ft_isalpha(str[i]) || str[i] == '_'))
		i++;
	if (str[i] != '=')
	{
		printf("THE VARIABLE MUST BE alphabetic");
		return(NULL);
	}
	node->key = (char *)safe_malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[i] && ft_isalpha(str[i]))
	{
		node->key[i] = str[i];
		i++;
	}
	node->key[i] = '\0';
	return(node->key);
}

char	*ft_save_value(char *str, t_env *node)
{
	int	i;
	int	j;
	int	size;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] != '=')
	{
		printf("Attention, export has to work with '=' sign\n");
		return (NULL);
	}
	i++;
	j = i;
	/* 
	ZDE ŘEŠIT QUOTES "" A ''
	if quotes

	else
	{ */
		while (str[i] && ft_isprint(str[i]))
		{
			i++;
		}
		size = i - j;
		i = j;
		j = 0;
		node->value = (char *)safe_malloc((size + 1) * sizeof(char));
		while (str[i] && ft_isprint(str[i]))
		{
			node->value[j] = str[i];
			i++;
			j++;
		}
		node->value[i] = '\0';
	//}	
	printf("value is : %s\n", node->value);
	return(node->value);
}

void	ft_export(t_list *list)
{
	char	*str;
	t_env	*node;

	str = list->cmd_text;
	node = (t_env *)safe_malloc(sizeof (t_env));
	if (ft_save_key(str, node) == NULL)
		return;
	//node->next = NULL;
	//kontrola
	if (ft_save_value(str, node) == NULL)
		return ;
	printf("%s = %s \n", node->key, node->value);
	//append

	return ;
}
