#include "rx_loop.h"
#include "rx_read_line.h"
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

        printf("%s\n", line);

        free(line);
    }
    while(status);
}
