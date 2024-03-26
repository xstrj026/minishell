#include "../../include/minishell.h"

void	ft_free_parsed_cmd_operator(t_array array)
{
	int	i;

	i = 0;
	while (array.cmd[i])
	{
		free(array.cmd[i]);
		i++;
	}
	i = 0;
	while (array.operator[i])
	{
		free(array.operator[i]);
		i++;
	}
	free(array.cmd);
	free(array.operator);
	return ;
}

void	free_list(t_list **list)
{
	// t_list	*tmp;
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
		free(current);
		current = current->next;
	}
		free(*list);
	return ;
}

void	free_tokens()
{}

//array --- uvnitr jsou 2 pole ktere je treba uvolnit
void	ft_free_all(t_list **list, t_token *operator_tok, t_array array)
{
	if (array.cmd != NULL && array.operator != NULL)
		ft_free_parsed_cmd_operator(array);
	else if (operator_tok != NULL)
		free(operator_tok);
	else if (*list != NULL)
		free_list(list);
	if (DEBUG_MODE) 
		printf(RED"All freed \n"RST);
	return ;
}