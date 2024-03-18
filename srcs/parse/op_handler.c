#include "../../include/minishell.h"

void	operator_handler(t_op operator)
{
	if (operator == INPUT_REDIR)
	{
		printf(Y"I'm a hustler amamama hustler and operator < \n"RST);
	}
	else if (operator == OUTPUT_REDIR)
	{
		printf(Y"I'm blueee dabdabi dabadai and operator > \n"RST);
	}
	else if (operator == INPUT_DELIM)
	{
		printf(Y"I'm freeeeeeee and operator <<\n"RST);
	}
	else if (operator == OUTPUT_REDIR_A)
	{
		printf(Y"I'm grooot and operator >>\n"RST);
	}
	else if (operator == PIPE)
	{
		printf(Y"I'm only huuuuuuman after alllllll and operator | \n"RST);
		//i_am_a_pipe(tkn, i);
	}
}


void	op_tumbler(t_token *tkn, t_array array, t_list *list)
{
	int array_size = op_size(array);
	int i = 0;
	if (list == NULL)
		return ;
	while(i < array_size)
	{
		operator_handler(tkn[i].token_type);
		i++;
	}
}