#include "../../include/minishell.h"

t_list	*find_last(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int     print_size(t_list* node)
{
    int i;

    i = 0;
    while(node)
    {
        node = node->next;
        i++;
    }
    return(i);
}

void print_list(t_list* node) 
{
	while (node != NULL)
	{
    	printf("%s -> ", node->branch);
    	node = node->next;
	}
	

    printf("NULL\n");
}

// t_list* createNode(char* branch) 
// {
//     t_list* newNode = (t_list*)malloc(sizeof(t_list));
//     if (newNode == NULL) {
//         printf("Memory allocation failed.\n");
//         exit(1);
//     }
//     newNode->branch = branch;
//     newNode->next = NULL;
//     newNode->prev = NULL;
//     return (newNode);
// }

// void appendNode(t_list **head, char *branch) 
// {
//     t_list* newNode = createNode(branch);
//     if (*head == NULL) 
//     {
//         *head = newNode;
//     } 
//     else 
//     {
//         t_list* lastNode = *head;
//         while (lastNode->next != NULL) 
//         {
//             lastNode = lastNode->next;
//         }
//         lastNode->next = newNode;
//         newNode->prev = lastNode;
//     }
// }

// void append_branch(t_parsed cmd_op, t_list *list) {
//     int i = 0;
//     while (cmd_op.cmd[i] != NULL) { // Ensure cmd is not NULL
//         printf("\n cmd_op.cmd[i] is %s", cmd_op.cmd[i]);
//         appendNode(&list, cmd_op.cmd[i]); // Append the command
//         if (cmd_op.operator[i] != NULL) { // Check if operator exists and is not NULL
//             printf("\n cmd_op.operator[i] is %s", cmd_op.operator[i]);
//             appendNode(&list, cmd_op.operator[i]); // Append the operator
//         }
//         i++;
//     }
//     printf("\n\n APPENDING FINISHED\n");
// }




void	append_branch(t_parsed cmd_op, t_list *list)
{
	int	i;

	i = 0;
	while (cmd_op.cmd[i])
	{
		printf("\n cmd_op.cmd[i] is %s", cmd_op.cmd[i]);
		append_node(&list, cmd_op.cmd[i]);
		if (cmd_op.operator[i])
		{
			printf("\n cmd_op.operator[i] is %s", cmd_op.operator[i]);
			append_node(&list, cmd_op.operator[i]);
		}
		i++;
	}
	printf("\n\n APPENDING FINISHED\n");
}



void	append_node(t_list **stack, char *branch)
{
	t_list	*node;
	t_list	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_list));
	printf("\n memory for node alocated ");
	if (!node)
		return ;
	node->next = NULL;
	node->branch = branch;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

// void	create_list(t_list *cmd_args, char *input)
// {
// 	cmd_args;
// }