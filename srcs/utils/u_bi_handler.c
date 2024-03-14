#include "../../include/minishell.h"

void	ft_free_parsed_cmd_operator(t_parsed cmd_op)
{
	int	i;

	i = 0;
	while (cmd_op.cmd[i])
	{
		free(cmd_op.cmd[i]);
		i++;
	}
	i = 0;
	while (cmd_op.operator[i])
	{
		free(cmd_op.operator[i]);
		i++;
	}
	free(cmd_op.cmd);
	free(cmd_op.operator);
	return ;
}

void	free_list(t_list **list)
{
	t_list	*tmp;
	t_list	*current;

	if (!list)
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

//cmd_op --- uvnitr jsou 2 pole ktere je treba uvolnit
void	ft_free_all(t_list **list, char *input, t_token *operator_tok, t_parsed cmd_op)
{
	if (cmd_op.cmd || cmd_op.operator)
		ft_free_parsed_cmd_operator(cmd_op);
	if (operator_tok)
		free(operator_tok);
	free_list(list);
	free(input);
	return ;
}

void	ft_exit(t_list **list, char *input, t_token *operator_tok, t_parsed cmd_op)
{
	printf("\nft_exit: Free memory \nCLosing minishell\n");
	ft_free_all(list, input, operator_tok, cmd_op);
	exit(1);
}


void	s_cmd_handler(t_list **list, char *input, t_token *operator_tok, t_parsed cmd_op ,t_cmd cmd)
{
	if (cmd == ECHO)
		printf(Y"I beleive i can flyyyyyyy and command echo \n"RST);
	else if (cmd == CD)
		printf(Y"Dont worry and be haaapy\n"RST);
	else if (cmd == PWD)
		printf(Y"Knock knock knocing on heaveeens doooor\n"RST);
	else if (cmd == EXPORT)
		printf(Y"Rideeers on the stoooooorm\n"RST);
	else if (cmd == UNSET)
		printf(Y"Aaaaall you neeeeed is love\n"RST);
	else if (cmd == ENV)
		printf(Y"Could you be looooved and be loooved\n"RST);
	else if (cmd == EXIT)
	{
		printf(Y"Liviiing next door Aaaaalice\n"RST);
		ft_exit(list, input, operator_tok, cmd_op);
	}
}

void set_func(t_list **list, char *input, t_token *operator_tok, t_parsed cmd_op, t_list* node) 
{

	if (if_cmd(node->branch, "echo"))
	{
        node->comand = ECHO;
		node->cmd_text = str_cut(node->branch,"echo");
		printf(G"Priniting echo: %s\n"RST, node->cmd_text);
		
	}
    else if (if_cmd(node->branch, "cd"))
	{
        node->comand = CD;
		node->cmd_text = str_cut(node->branch,"cd");
	}
    else if (!(if_strwcmp(node->branch, "pwd")))
        node->comand = PWD;
    else if (!(if_strwcmp(node->branch, "export")))
        node->comand = EXPORT;
    else if (!(if_strwcmp(node->branch, "unset")))
        node->comand = UNSET;
    else if (!(if_strwcmp(node->branch, "env")))
        node->comand = ENV;
    else if (!(if_strwcmp(node->branch, "exit")))
        node->comand = EXIT;
	else
		node->comand = ELSE;
	s_cmd_handler(list, input, operator_tok, cmd_op, node->comand);
}