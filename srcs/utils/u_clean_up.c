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
	if (cmd == NULL) {
        return;
    }
    
    for (int i = 0; cmd[i] != NULL; ++i) {
        free(cmd[i]);
    }
    free(cmd);
}

void	ft_free_parsed_cmd_operator(t_array array)
{
	free_cmd(array.cmd);
	free_operators(array.operator);
	return ;
}

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
		tmp = current;
		current = current->next;
		free(tmp);
	}
	return ;
}

void	free_tokens()
{}

//array --- uvnitr jsou 2 pole ktere je treba uvolnit
void	ft_free_all(t_list **list, t_token *operator_tok, t_array array)
{
	ft_free_parsed_cmd_operator(array);
	if (operator_tok != NULL)
		free(operator_tok);
	if (*list != NULL)
	{
		free_list(list);
	}
	if (DEBUG_MODE) 
		printf(RED"All freed \n"RST);
	return ;
}