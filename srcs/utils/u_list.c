#include "../../include/minishell.h"


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
    if (cmd_op.cmd[i] == NULL) {
        printf("-minishell:syntax error near unexpected token `%s'\n", cmd_op.operator[i]);
        exit(1);
    }
    while(cmd_op.cmd[i]) 
	{
        append_node(head, cmd_op.cmd[i]);
        if(cmd_op.operator[i]) {
            append_node(head, cmd_op.operator[i]);
        }
        i++;
    }
}

void print_list(t_list* node) 
{
    printf(G"Here we are testing linked list: "RST);
	while (node != NULL)
	{
    	printf("%s", node->branch);
    	node = node->next;
	}
    printf("\n");
}

