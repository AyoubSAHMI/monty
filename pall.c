#include "monty.h"
extern stack_t *stack;
/**
* pall - a function that prints the values of the stack
* @stack: the stack we're printing
* @line_number: unused parameter
* Return: nothing
*/
void pall(stack_t **stack)
{
    stack_t *current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

