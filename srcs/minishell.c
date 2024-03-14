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
	t_parsed cmd_op;
	t_list* list;
	t_token *operator_tok;

	while (1)
	{
		input = readline("minishell$ ");
		if (input) 
		{
			list = NULL;
			cmd_op = parse_input(input);
			append_branch(cmd_op, &list);
	
			operator_tok = tkn_find(list, cmd_op);
			op_tumbler(operator_tok, cmd_op);
			set_func(&list, input, operator_tok, cmd_op, list);
			
					
			/*test_print(cmd_op);
			print_list(list);*/
			//
			ft_free_all(&list, input, operator_tok, cmd_op);
			// free(input);
			// free(cmd_op.cmd);
			// free(cmd_op.operator);
			// free(operator_tok); // Free the allocated memory
		}
	}
}