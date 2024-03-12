#include "../../include/minishell.h"


// void	set_token(t_list *node)
// {
// 	t_token test;

// 	if (!strcmp(node->branch, "|"))
// 		test.token_type = PIPE;
// 	else if (!strcmp(node->branch, ">"))
// 		test.token_type = OUTPUT_REDIR;
// 	else if (!strcmp(node->branch, ">>"))
// 		test.token_type = OUTPUT_REDIR_A;
// 	else if (!strcmp(node->branch, "<"))
// 		test.token_type = INPUT_REDIR;
// 	else if (!strcmp(node->branch, "<<"))
// 		test.token_type = INPUT_DELIM;
// 	else
// 		test.token_type = CONTENT;
// 	node->token = test;
// 	if (node->token.token_type >= INPUT_REDIR && node->token.token_type <= PIPE)
// 	{
// 		node->token.next = node->next->branch;
// 		node->token.prev = node->prev->branch;
// 	}
// }

t_list* create_node(char* branch) 
{
    t_list* newNode = (t_list*)malloc(sizeof(t_list));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->branch = branch;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append_node(t_list** head, char* branch) 
{
    t_list* newNode = create_node(branch);
    if (*head == NULL) {
        *head = newNode;
    } else {
        t_list* lastNode = *head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->prev = lastNode;
    }
}

void append_branch(t_parsed cmd_op, t_list **head) 
{
    int i;

    i = 0;
    while(cmd_op.cmd[i]) 
	{
        append_node(head, cmd_op.cmd[i]);
        if(cmd_op.operator[i]) {
            append_node(head, cmd_op.operator[i]);
        }
        i++;
    }
	// i = 0;
	// while (*head)
	// {
	// 	set_token(*head);
	// 	(*head)++;
	// }
}

void print_list(t_list* node) 
{
    printf("Linked List: ");
	while (node != NULL)
	{
    	printf(RED"%s"RST, node->branch);
		// printf("%d", node->token.token_type);
    	node = node->next;
	}
    printf("\n");
}