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
	t_list* head;

	while (1)
	{
		input = readline("minishell$ ");
		if (input) 
		{
			head = NULL;
			cmd_op = parse_input(input);
			append_branch(cmd_op, &head);
	
			t_token *myTokens = tkn_find(head,cmd_op);
			op_tumbler(myTokens, cmd_op);
			/*test_print(cmd_op);
			print_list(head);*/

			free(input);
			free(myTokens); // Free the allocated memory
		}
	}
}