#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;
    char *line = NULL;
    

    unsigned int line_number = 0;
    char *opcode;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    line = malloc(MAX_LINE_LENGTH); 

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        line_number++;

        
        if (line[strlen(line) - 1] != '\n' && !feof(file))
        {
            fprintf(stderr, "Error: Line too long at line %u\n", line_number);
            free(line);
            fclose(file);
            return EXIT_FAILURE;
        }

        opcode = strtok(line, " \t\n");

        if (opcode != NULL)
        {
            if (strcmp(opcode, "push") == 0)
            {
                push(&stack, line_number);
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(&stack, line_number);
            }
            
        }
    }

    free(line);
    fclose(file);

    return EXIT_SUCCESS;
}
