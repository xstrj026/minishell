#include "minishell.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>
#include <limits.h>
#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char **argv)
{
    char *input;

    // Read input from the user with a prompt
    input = readline("Enter something: ");

    // Check if readline returned NULL (e.g., EOF was encountered)
    if (input) {
        printf("You entered: %s\n", input);
        free(input); // Free the allocated memory
    } else {
        printf("No input read.\n");
    }
    // pid_t   pid;

    // pid = getpid();
    // while(1)
    // {
    //     ft_printf("MY PID IS: %d\n", getpid());
    //     usleep(10);
    // }
    return (0);
}