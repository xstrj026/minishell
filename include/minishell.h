#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"


# define RST	"\033[0m"
# define RED	"\033[1;31m"
# define G		"\033[1;32m"
# define Y		"\033[1;33m"
# define B		"\033[1;34m"
# define M		"\033[1;35m"
# define C		"\033[1;36m"
# define W		"\033[1;37m"


/****************************************
 *   ___ _ __  _   _ _ __ ___  ___     *
 *  / _ \ '_ \| | | | '_ ` _ \/ __|    *
 * |  __/ | | | |_| | | | | | \__ \    *
 *  \___|_| |_|\__,_|_| |_| |_|___/    *
 ****************************************/

typedef enum e_op
{
	INPUT_REDIR, // "<" which redirects input
	OUTPUT_REDIR, // ">" which redirects output
	INPUT_DELIM, // "<<" which reads input until a delimiter is seen
	OUTPUT_REDIR_A, // ">>" which redirects output in append mode
	PIPE, // Pipe character "|"
	CONTENT,
}			t_op;

typedef enum e_cmd
{
	ECHO, // echo with option -n
	CD, // cd with a relative path
	PWD, // pwd with no options
	EXPORT, // export with no options
	UNSET, // unset with no options
	ENV, // env with no options or arguments
	EXIT, // exit with no options
	ELSE,
}			t_cmd;

typedef enum e_error
{
	STAND_ERROR,
	TOKEN_UNEXP,
}			t_error;

typedef enum e_sign
{
	STAND_SIGN,
}			t_sign;

/****************************************
 *     | |                 | |         	*
 *  ___| |_ _ __ _   _  ___| |_ ___    	*
 * / __| __| '__| | | |/ __| __/ __|   	*
 * \__ \ |_| |  | |_| | (__| |_\__ \   	*
 * |___/\__|_|   \__,_|\___|\__|___/   	*
 ****************************************/


typedef struct s_list t_list;
typedef struct s_parsed
{
    char **operator;
    char **cmd;
}				t_parsed;

typedef struct s_token
{
	t_op	token_type;
	t_list	*list;
	char	*next;
	char	*prev;
	int		id;
}				t_token;

//t_token			*token;
struct s_list
{
	t_token			*token;
	t_cmd			comand;
	char			*cmd_text;
	char			*branch;
	struct s_list	*next;
	struct s_list	*prev;
};


/********************************************************
*                 | |      | |                          *
*  _ __  _ __ ___ | |_ ___ | |_ _   _ _ __   ___  ___   *
* | '_ \| '__/ _ \| __/ _ \| __| | | | '_ \ / _ \/ __|  *
* | |_) | | | (_) | || (_) | |_| |_| | |_) |  __/\__ \  *
* | .__/|_|  \___/ \__\___/ \__|\__, | .__/ \___||___/  *
* | |                            __/ | |                *
* |_|                           |___/|_|                *
********************************************************/

//utils


void	print_errors(t_error error);
void	print_sign(t_sign sign);
char	**ft_words(char *str);
char	**ft_cmd(char *str);
void 	test_print(t_parsed cmdWords);
t_parsed parse_input(char *str);
void	operator_handler(t_op operator, t_token *tkn, int i);
void 	s_cmd_handler(t_list **list, char *input, t_token *operator_tok, t_parsed cmd_op, t_cmd cmd);
char *ft_strncpy(char *s1, char *s2, int n);
int ft_strcmp(char *s1, char *s2);


void	print_list(t_list *stack);
t_list* create_node(char* branch);
void 	append_node(t_list** head, char* branch);
void 	append_branch(t_parsed cmd_op, t_list **head);
void 	print_list(t_list* node);


t_token* tkn_find(t_list* head, t_parsed op_cmd);
void	op_tumbler(t_token *tkn, t_parsed cmd_op);

int op_size(t_parsed cmdWords);
int i_am_a_pipe(t_token *tkn, int i);


int if_strwcmp(char *s1, char *s2);
void set_func(t_list **list, char *input, t_token *operator_tok, t_parsed cmd_op, t_list* node);
char	*str_cut(char *haystack, char *needle);
int	if_cmd(char *haystack,char *needle);

void	ft_free_all(t_list **list, char *input, t_token *operator_tok, t_parsed cmd_op);


#endif