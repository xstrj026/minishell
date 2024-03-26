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
# include <dirent.h>


# define RST	"\033[0m"
# define RED	"\033[1;31m"
# define G		"\033[1;32m"
# define Y		"\033[1;33m"
# define B		"\033[1;34m"
# define M		"\033[1;35m"
# define C		"\033[1;36m"
# define W		"\033[1;37m"

# ifndef DEBUG_MODE
# define DEBUG_MODE 1
# endif


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
	ERROR_MALLOC,
}			t_error;

typedef enum e_quotes
{
	SINGLE,
	DOUBLE,
	ZERO,
}			t_quotes;

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


typedef struct s_env t_env;
typedef struct s_list t_list;

/* struct contains 2 arrays: **operators and **commands (arrays of string)*/
typedef struct s_array
{
	char	**operator;
	char	**cmd;
}				t_array;


struct s_env
{
	char	*key;
	char	*value;
	t_env	*next; 
};

/*  */
typedef struct s_token
{
	t_list	**list;
	t_op	token_type;
	int		id;//pořadí výskytu číslované od 0
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
typedef struct s_segment
{
    char *string;    // Stores the substring
    char quote_type; // Stores the type of quote ('\'', '\"', or 0 if none)
} t_segment;

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
char	**ft_cmd(char *str);
char	**ft_operators(char *str);
void 	test_print(t_array cmdWords);
t_array parse_input(char *str);
void	operator_handler(t_op operator);
void	s_cmd_handler(t_list *list, char *input, t_token *operator_tok, t_array array ,t_cmd cmd);
char *ft_strncpy(char *s1, char *s2, int n);
int ft_strcmp(char *s1, char *s2);


void	print_list(t_list *stack);
t_list* create_node(char* branch);
void 	append_node(t_list** head, char* branch);
void 	append_branch(t_array array, t_list **head);
void 	print_list(t_list* node);


t_token* tkn_find(t_list* head, t_array op_cmd);
void	op_tumbler(t_token *tkn, t_array array, t_list *list);

int op_size(t_array cmdWords);
int i_am_a_pipe(t_token *tkn, int i);


int if_strwcmp(char *s1, char *s2);
void set_func(char *input, t_token *operator_tok, t_array array, t_list* list);
char	*str_cut(char *haystack, char *needle);
int	if_cmd(char *haystack,char *needle);
int	if_n_cmd(char *haystack,char *needle);

void	ft_free_all(t_list **list, char *input, t_token *operator_tok, t_array array);
char *ft_strcpy(char *dst, char *src);
void	ft_exit(t_list **list, char *input, t_token *operator_tok, t_array array, int exit_number);
void  	ft_pwd();
char	**ft_env(char *str);
char *ft_key_value(char *str, t_env *env);
void handle_echo_quote(char *str);
void d_test_print(char *str);
void f_test_print(char *str);
void i_am_testing_quotes();
void qt_list_update(t_list* node);
int if_two_quote(char *str, char c);
int if_quote(char *str, char c);

char	*ft_strjoin_u(char *s1, char *s2);
size_t	ft_strlcpy_u(char *dst, char *src, size_t size);
size_t	ft_strlcat_u(char *dst, char *src, size_t size);
int if_c_quote(char a, char c);
void exec_list_update(t_list** list);
char	*echo_n_cut(char *haystack,char *needle);
int quote_handle(char *str);
int wc_quote(char *str);
void print_segments(char *str);
t_segment	*ft_q_split(char *str);
void skip_quotes(char *str);
void	echo_print(char *str);
void	quote_handler(char *str, char type);
void handle_dollar(char *str);
void free_segments(t_segment *segments);
int if_strchr(char *str, char c);
int one_case(char *str);

//export
void	*safe_malloc(size_t bytes);
char	*ft_save_value(char *str, t_env *node);
void	ft_export(t_list *list);
#endif