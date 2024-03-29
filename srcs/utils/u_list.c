#include "../../include/minishell.h"


t_list* create_node(char* branch) 
{
	t_list*	newNode;
	
	newNode = (t_list *)ft_calloc(1, sizeof(t_list));
	if (newNode == NULL)
	{
		printf("Memory allocation failed.\n");
		exit(1);
    }
    newNode->branch = branch;
	newNode->cmd_text = NULL;
	newNode->token = NULL;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append_node(t_list** list, char* branch) 
{
    t_list*	newNode = create_node(branch);

    if (*list == NULL)
	{
		*list = newNode;
    }
	else
	{
        t_list *lastNode = *list;
        while (lastNode->next != NULL)
		{
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->prev = lastNode;
    }
}

void append_branch(t_array *array, t_list **list) 
{
	int i;

	i = 0;
	
	if (!(*array).command_exist && !(*array).operator_exist)
	{
		return ;
	}
	if ((*array).command_exist && (*array).cmd[i] && (*array).cmd[i+1] == NULL && (*array).operator_exist == false) 
	{
		if(!if_cmd((*array).cmd[i],"echo") && !if_cmd((*array).cmd[i],"cd") && !if_cmd((*array).cmd[i],"pwd") && !if_cmd((*array).cmd[i],"export") && !if_cmd((*array).cmd[i],"unset") && !if_cmd((*array).cmd[i],"env") && !if_cmd((*array).cmd[i],"exit"))
		{
			printf("-minishell: %s: command not found'\n", (*array).cmd[i]);
			// free((*array).cmd);
			return ;
		}
	}
	if ((*array).operator_exist && (*array).operator[i] && (*array).operator[i+1] == NULL && !(*array).cmd[i])
	{
		printf("-minishell:syntax error near unexpected token `%s'\n", (*array).operator[i]);
		return ;
	}

	while((*array).cmd[i])
	{
		// printf("\n(*array).cmd[i] == %s\n", (*array).cmd[i]);
		// printf("\n(*array).cmd[i] == %s\n", (*array).cmd[i+1]);
		append_node(list, (*array).cmd[i]);
		// printf("\n(*array).cmd[i] == %s\n", (*list)->branch);
		// printf("\n(*array).cmd[i] == %p\n", (*list)->next);
		if((*array).operator_exist == true && (*array).operator[i])
		{
			// printf(, (*array).operator[i]);
			append_node(list, (*array).operator[i]);
		}
		i++;
	}
}

void print_list(t_list* node) 
{
    int i;
    i = 0;
    if(DEBUG_MODE)
    {
        printf(G"Here we are testing linked list:\n"RST);
	    while (node != NULL)
	    {
            printf(RED"node %d:"RST, i);
    	    printf("%s\n", node->branch);
    	    node = node->next;
            i++;
	    }
        printf(RED"node %d:"RST, i);
        printf("NULL");
        printf("\n");
    }
}

//join strings and update list
//should clear list from memory allocation on stjoin
void qt_list_update(t_list* node)
{
	char* new_branch;

    while (node != NULL)
	{
        t_list* current = node;
        t_list* temp;
        bool joined = false;

        while (current->next != NULL && !if_two_quote(current->branch, 39)) 
        {
            if (!if_quote(current->next->branch, 39) || current == node) 
            {
                new_branch = ft_strjoin_u(current->branch, current->next->branch);
                current->branch = new_branch;
                temp = current->next;
                current->next = current->next->next;
                free(temp); // Assuming t_list nodes are dynamically allocated.
                joined = true;
            } else {
                break;
            }
        }
        while (current->next != NULL && !if_two_quote(current->branch, 34)) 
        {
            if (!if_quote(current->next->branch, 34) || current == node) 
            {
                new_branch = ft_strjoin_u(current->branch, current->next->branch);
                current->branch = new_branch;
                temp = current->next;
                current->next = current->next->next;
                free(temp); // Assuming t_list nodes are dynamically allocated.
                joined = true;
            } else {
                break;
            }
        }
        if (!joined) {
            node = node->next;
        }
    }
}

/* if (node->branch) 
                free(node->branch); // Assuming the old node->branch needs to be freed. */

void exec_list_update(t_list** list) 
{
    char* new_branch;
    bool executed = false;

    if (printf("testing"))
        executed = true;
    if (executed)
    {
        if (!*list || !(*list)->next->next)
            return ;
		*list = (*list)->next->next;
        (*list)->prev = NULL;
		new_branch = "updated result";
        (*list)->branch = new_branch;
    }
}
