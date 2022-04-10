#include "rx_execute.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Declarations of built-in shell commands */
int rx_cd(char **args);
int rx_help(char **args);
int rx_exit(char **args);

/* List of built-in commands, and their corresponding functions */
char *builtin_str[] = {
        "cd",
        "help",
        "exit"
};

int (*builtin_func[])(char**) = {
        &rx_cd,
        &rx_help,
        &rx_exit
};

int rx_num_builtins()
{
    return sizeof(builtin_str) / sizeof(char*);
}

/* Implementation of built-in commands */

int rx_cd(char **args)
{
    if(args[1] == NULL)
    {
        fprintf(stderr, "rx: expected argument to \"cd\"\n");
    }
    else
    {
        if(chdir(args[1]) != 0)
        {
            perror("rx");
        }
    }
    return 1;
}

int rx_help(char **args)
{
    printf("RaxonPC's rx shell\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");

    for (int i = 0; i < rx_num_builtins(); i++) {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Use the \"man\" command for information on other programs.\n");
    return 1;
}

int rx_exit(char **args)
{
    return 0;
}

int rx_execute(char **args)
{
    return 1;
}