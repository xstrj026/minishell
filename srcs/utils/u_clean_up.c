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
	t_list	*tmp;
	t_list	*current;

	if (list == NULL)
		return ;
	current = *list;
	while (current)
	{
		tmp = current->next;
		free(current->token);
		free(current->cmd_text);
		free(current->branch);
		current = tmp;
	}
	return ;
}

//array --- uvnitr jsou 2 pole ktere je treba uvolnit
void	ft_free_all(t_list **list, char *input, t_token *operator_tok, t_array array)
{
	if (array.cmd || array.operator)
			ft_free_parsed_cmd_operator(array);
	else if (operator_tok)
		free(operator_tok);
	else if (*list)
		free_list(list);
	free(input);
	if (DEBUG_MODE) 
		printf(RED"All freed \n"RST);
	return ;
}