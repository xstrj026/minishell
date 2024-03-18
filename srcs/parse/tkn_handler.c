#include "../../include/minishell.h"

//in this way after update next and prev from struct wouldnt be updated :/
t_token* tkn_find(t_list* head, t_array array)
{
	int i;
	t_token *tkn;
	int array_size;

	array_size = op_size(array);
	tkn = (t_token *)malloc(array_size * sizeof(t_token));
	if (tkn == NULL)
		return (NULL);
	i = -1;
	while(head)
	{
		if (!ft_strcmp(head->branch, "|"))
		{
            i++;
			tkn[i].token_type = PIPE;
		}
		else if (!ft_strcmp(head->branch, ">>"))
		{
            i++;
			tkn[i].token_type = OUTPUT_REDIR_A;
		}
		else if (!ft_strcmp(head->branch, ">"))
		{
            i++;
			tkn[i].token_type = OUTPUT_REDIR;
		}
		else if (!ft_strcmp(head->branch, "<"))
		{
            i++;
			tkn[i].token_type = INPUT_REDIR;
		}
		else if (!ft_strcmp(head->branch, "<<"))
		{
            i++;
			tkn[i].token_type = INPUT_DELIM;
		}
		head = head->next;
	}
    return(tkn);
}
