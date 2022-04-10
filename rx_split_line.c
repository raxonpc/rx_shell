#include "rx_split_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define RX_TOK_BUFSIZE 64
#define RX_TOK_DELIM " \t\a\r\n"

/* returns a NULL terminated array of tokens */
char **rx_split_line(char *line)
{
    int bufsize = RX_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if(!tokens)
    {
        fprintf(stderr, "rx: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, RX_TOK_DELIM);
    while(token != NULL)
    {
        tokens[position++] = token;

        /* buffer exceeded - increase size
         * and reallocate */
        if(position >= bufsize)
        {
            bufsize += RX_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));

            if (!tokens)
            {
                fprintf(stderr, "rx: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, RX_TOK_DELIM);
    }

    tokens[position] = NULL;
    return tokens;
}