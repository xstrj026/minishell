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
}			t_op;

typedef enum e_cmd
{
	ECHO_OPTION_N, // echo with option -n
	CD_RELATIVE, // cd with a relative path
	CD_ABSOLUTE, // cd with an absolute path
	PWD, // pwd with no options
	EXPORT, // export with no options
	UNSET, // unset with no options
	ENV, // env with no options or arguments
	EXIT, // exit with no options
}			t_cmd;

typedef enum e_error
{
	STAND_ERROR,
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

typedef struct s_parsed
{
    char **array_cmd;
    char **array_word;
}				t_parsed;

typedef struct s_list {
	char	*word;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

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

int		ft_putstr_fd(char *s);
void	print_errors(t_error error);
void	print_sign(t_sign sign);
char *ft_strncpy(char *s1, char *s2, int n);
char	**ft_words(char *str);
char	**ft_cmd(char *str);
void test_print(t_parsed cmdWords);
t_parsed parse_input(char *str);
int	ft_strstr(const char *haystack, const char *needle);

#endif