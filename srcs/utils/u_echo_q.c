#include "../../include/minishell.h"
#include <ctype.h>

int wc_quote(char *str) {
    int i = 0;
    int wc = 0;
    char current_quote = 0; // Variable to keep track of the current quote type
    int in_segment = 0; // Flag to indicate if we are currently in a non-quoted segment

    while (str[i]) {
        if ((str[i] == 39 || str[i] == 34) && current_quote == 0) { // Start of a quoted segment
            current_quote = str[i];
            if (!in_segment) {
                wc++;
                in_segment = 1; // We're in a segment now
            }
        }
        else if (str[i] == current_quote) { // End of a quoted segment
            current_quote = 0;
        }
        else if (!current_quote && str[i] != ' ' && !in_segment) { // Start of a non-quoted segment
            wc++;
            in_segment = 1;
        }
        else if (!current_quote && str[i] == ' ' && in_segment) { // End of a non-quoted segment
            in_segment = 0;
        }
        i++;
    }

    return wc;
}

static char *q_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

/* t_segment	*ft_q_split(char *str)
{
	int i = 0;
    int end = 0;
	int start = 0;
	int k = 0;
	int wc;
    char current_quote = 0; // Variable to keep track of the current quote type
    char current_type = 0;
    int in_segment = 0;
	wc = wc_quote(str);
	t_segment *out = (t_segment *)malloc(sizeof(t_segment) * (wc + 1));
	while (str[i])
	{
        if ((str[i] == '\'' || str[i] == '\"') && current_quote == 0) 
        {
            current_quote = str[i];
            current_type = current_quote;
            in_segment = 0;
            start = i;
        }
        else if (str[i] == current_quote)
        {
            i++;
            end = i;
            while(str[end] == ' ')
            {
                end++;
            }
            current_quote = 0;
        }
		else if (!current_quote && !in_segment)
        {
            current_type = 0;
            in_segment = 1;
            start = i;
        }
        else if(in_segment && !current_quote)
        {
            // Loop to find the end of the segment, which is a quote or the end of the string
            while(str[i] != '\'' && str[i] != '\"')
            {
                i++;
            }
            // If we're ending because we found a quote, we decrement `i` to include the last character before the quote
            if (str[i] == '\'' || str[i] == '\"') 
                i--;

            end = i; // Set the end to where we found a quote or the end of the string
            in_segment = 0; // We're no longer in a segment
        }
		if (end > start)
        {
            out[k].string = (char *)malloc(sizeof(char) * ((end - start) + 1));
            q_strncpy(out[k].string, &str[start], end - start);
            out[k].quote_type = current_type; // Store the quote type
            k++;
        }
        i++;
	}
	out[k].string = NULL; // Mark the end of the array
    return out;
} */

t_segment *ft_q_split(char *str)
{
    int i = 0, start = -1, k = 0;
    char current_quote = 0;
    int wc = wc_quote(str); // Assume this correctly counts the segments
    t_segment *out = (t_segment *)malloc(sizeof(t_segment) * (wc + 1));

    while (str[i]) 
    {
        if ((str[i] == '\'' || str[i] == '\"') && (i == 0 || str[i-1] != '\\'))
        {
            if (current_quote == 0) 
            {
                current_quote = str[i];
                start = i;
            } 
            else if (current_quote == str[i]) 
            {
                while(str[i+1] == ' ')
                    i++;
                out[k].string = (char *)malloc(i - start + 2);
                q_strncpy(out[k].string, &str[start], i - start + 1);
                out[k].string[i - start + 1] = '\0';
                out[k].quote_type = current_quote;
                k++;
                current_quote = 0;
                start = -1;
            }
        } 
        else if (start == -1 && str[i] != ' ')
            start = i;
        else if (start != -1) 
        {
            int end = i;
            if ((str[i] == ' ' && current_quote == 0) || str[i + 1] == '\0') {
                if (str[i + 1] == '\0' && (str[i] != ' ' || current_quote != 0)) 
                {
                    end = i + 1;
                }
                while (str[end] == ' ' && str[end] != '\0') 
                {
                    end++;
                }
                out[k].string = (char *)malloc(end - start + 1);
                q_strncpy(out[k].string, &str[start], end - start);
                out[k].string[end - start] = '\0';

                out[k].quote_type = current_quote ? current_quote : 0;
                k++;
                start = -1;
                current_quote = 0;
            }
        }

        i++;
    }
    out[k].string = NULL; // Terminate the array
    return out;
}

void free_segments(t_segment *segments)
{
    if (segments == NULL) {
        return; // No memory to free
    }

    // Free each dynamically allocated string within the array
    for (int index = 0; segments[index].string != NULL; ++index) {
        free(segments[index].string);
    }

    // Finally, free the array of structures itself
    free(segments);
}

void print_segments(char *str)
{
    t_segment *segments = ft_q_split(str);

    if (segments == NULL) {
        printf("No segments to display.\n");
        return;
    }

    for (int index = 0; segments[index].string != NULL; ++index)
    {
        printf("Segment %d:%s(Quote type: %c)\n", 
               index + 1, 
               segments[index].string, 
               segments[index].quote_type);
    }
    free_segments(segments);
}

