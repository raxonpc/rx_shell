#include "rx_read_line.h"
#include <stdio.h>
#include <stdlib.h>

#define RX_RL_BUFSIZE 1024

char *rx_read_line(void)
{
    int bufsize = RX_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    /* malloc error*/
    if(!buffer)
    {
        fprintf(stderr, "rx: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        /* read a character */
        c = getchar();

        /* If we hit EOF or newline character, we replace it with the null character
        and return */
        if(c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        }
        else
        {
            buffer[position] = (char)c;
        }
        ++position;

        /* when the buffer is exceeded */
        if(position >= bufsize)
        {
            bufsize += RX_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);

            if(!buffer)
            {
                fprintf(stderr, "rx: allocation error");
                exit(EXIT_FAILURE);
            }
        }
    }
}