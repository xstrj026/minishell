#include "../../include/minishell.h"

//in this way after update next and prev from struct wouldnt be updated :/
t_token* tkn_find(t_list* head, t_parsed op_cmd)
{
	int i;

    int array_size = op_size(op_cmd);
    t_token *tkn = (t_token *)malloc(array_size * sizeof(t_token));
    if (tkn == NULL)
        return (NULL);
    ft_memset(tkn, 0, array_size * sizeof(t_token));
    i = -1;
	while(head)
	{
		if (!ft_strcmp(head->branch, "|"))
		{
            i++;
			tkn[i].token_type = PIPE;
			tkn[i].next = head->next->branch;
			tkn[i].prev = head->prev->branch;
		}
		else if (!ft_strcmp(head->branch, ">>"))
		{
            i++;
			tkn[i].token_type = OUTPUT_REDIR_A;
			tkn[i].next = head->next->branch;
			tkn[i].prev = head->prev->branch;
		}
		else if (!ft_strcmp(head->branch, ">"))
		{
            i++;
			tkn[i].token_type = OUTPUT_REDIR;
			tkn[i].next = head->next->branch;
			tkn[i].prev = head->prev->branch;
		}
		else if (!ft_strcmp(head->branch, "<"))
		{
            i++;
			tkn[i].token_type = INPUT_REDIR;
			tkn[i].next = head->next->branch;
			tkn[i].prev = head->prev->branch;
		}
		else if (!ft_strcmp(head->branch, "<<"))
		{
            i++;
			tkn[i].token_type = INPUT_DELIM;
			tkn[i].next = head->next->branch;
			tkn[i].prev = head->prev->branch;
		}
		head = head->next;
	}
    return(tkn);
}