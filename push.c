#include "monty.h"
extern stack_t *stack;
/**
* push - a function that pushes a number to the stack
* @stack: the stack we're using
* @value: the value we push
* Return: nothing
*/
void push(stack_t **stack, int value)
{
stack_t *new_node = malloc(sizeof(stack_t));

if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;
if (*stack)
{
(*stack)->prev = new_node;
}
*stack = new_node;
}
