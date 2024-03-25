#include "../include/minishell.h"

//we have to parse input into words and aperators and save it into right order
//then read parsed input
//read a line. 1st word == command; read till operator or white space
//after operator is new 1st word == command
//if wrong order/wrong syntax -> free list && save to log file
//proper cleanup



int	main(void)
{
	char	*input;
	t_array array;
	t_list* list;
	t_token *op_tok;

	while (1)
	{
		input = readline("minishell$ ");
		add_history(input);
		list = NULL;
		array = parse_input(input);		
		append_branch(array, &list);
		qt_list_update(list);

		//print_list(list);
	
		op_tok = tkn_find(list, array);
		op_tumbler(op_tok, array, list);
		set_func(input, op_tok, array, list);
		
		// ft_free_all(&list, input, op_tok, array);
	}
}