#include "monty.h"
#include <ctype.h>
#include <stdio.h>

void push(stack_t **stack, unsigned int line_number)
{
    char *arg;
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    arg = strtok(NULL, " \t\n");
    if (!arg || (!isdigit(*arg) && *arg != '-'))

    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free(new_node);
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(arg);
    new_node->prev = NULL;

    if (*stack)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;  

    {
        stack_t *current = *stack;  

        while (current != NULL)
        {
            printf("%d\n", current->n);
            current = current->next;
        }
    }
}
