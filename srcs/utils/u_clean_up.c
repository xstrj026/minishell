#include "../../include/minishell.h"

void free_operators(char **operators) {
    if (operators == NULL) {
        return;
    }
    
    for (int i = 0; operators[i] != NULL; ++i) {
        free(operators[i]);
    }
    free(operators);
}

void free_cmd(char **cmd) {
	if (cmd == NULL) 
	{
		return;
    }
    for (int i = 0; cmd[i] != NULL; ++i) {
        free(cmd[i]);
    }
    free(cmd);
}

void	ft_free_parsed_cmd_operator(t_array **m_array)
{
	t_array	*array;
	int	i;

	i = 0;
	array = *m_array;
	if ((*array).command_exist == true)
	{
		if (DEBUG_MODE)
		{
			while (array->cmd[i])
			{
				printf(RED"command to delete%s\n"RST, array->cmd[i]);
				i++;
			}
		}
		i = 0;
		// free_cmd(array->cmd);
		while (array->cmd[i])
		{
			free(array->cmd[i]);
			i++;
		}
		free(array->cmd);
	}
	if ((*array).operator_exist == true)
		free_operators((*array).operator);
	return ;
}
/*
void free_list(t_list **list) {
    if (list == NULL || *list == NULL) {
        return;
    }
    
    t_list *current = *list;
    t_list *next;
    
    while (current != NULL) {
        next = current->next;
        
        free(current->token); // Uvolnění paměti pro řetězec v token
        free(current->cmd_text); // Uvolnění paměti pro řetězec v cmd_text
        if(current->branch != NULL)
			free(current->branch); // Uvolnění paměti pro řetězec v branch
        free(current); // Uvolnění paměti pro uzel
        
        current = next;
    }
    
    *list = NULL; // Nastavení ukazatele na NULL, aby se zabránilo neplatnému přístupu k paměti
} */

void	free_list(t_list **list)
{
	t_list	*tmp;
	t_list	*current;

	if (list == NULL)
		return ;
	current = *list;
	while (current && current->next != NULL)
	{
		// tmp = current->next;
		free(current->token);
		free(current->cmd_text);
		free(current->branch);
		if (current->prev != NULL)
		{
			free(current->prev);
		}
		tmp = current;
		current = current->next;
		free(tmp);
	}
	return ;
}

void	free_tokens()
{}

//array --- uvnitr jsou 2 pole ktere je treba uvolnit
void	ft_free_all(t_list **list, t_token *operator_tok, t_array **m_array)
{
	t_array	*array;

	array = *m_array;
	ft_free_parsed_cmd_operator(&array);
	if ((*array).operator_exist == true)///this is no necessary
	{
		if (operator_tok != NULL)
			free(operator_tok);
	}
	if (*list != NULL)
	{
		free_list(list);
	}
	if (DEBUG_MODE) 
		printf(RED"All freed \n"RST);
	return ;
}