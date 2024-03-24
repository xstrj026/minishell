#include "../../include/minishell.h"

void	quote_handler(char *str, char type)
{
	if (type == 39)
		skip_quotes(str);
	else
		handle_dollar(str);
}

void	echo_print(char *str)
{
    t_segment *segments = ft_q_split(str);
	int array_size = wc_quote(str);
	int i = 0;
	if (segments == NULL)
		return ;
	while(i < array_size)
	{
		quote_handler(segments[i].string, segments[i].quote_type);
		i++;
	}
    free_segments(segments);
}