#include "rx_launch.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int rx_launch(char **args)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if(pid == 0)
    /* child process */
    {
        if(execvp(args[0], args) == -1)
        {
            perror("rx");
        }
        exit(EXIT_FAILURE);
    }
    else if(pid < 0)
    /* error forking */
    {
        perror("rx");
    }
    else
    /* parent process */
    {
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        }
        while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}