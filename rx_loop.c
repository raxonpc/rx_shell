#include "rx_loop.h"
#include "rx_read_line.h"
#include "rx_split_line.h"
#include "rx_execute.h"
#include <stdio.h>
#include <stdlib.h>

void rx_loop(void)
{
    int status = 1;
    char *line;
    char **args;

    do
    {
        printf("> ");

        line = rx_read_line();
        args = rx_split_line(line);

        status = rx_execute(args);

        free(line);
        free(args);
    }
    while(status);
}
