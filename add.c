#include "monty.h"
extern stack_t *stack;
/**
* add - adds the top two elements of the stack
* @stack: the stack we're using
* @line_number: empty line
* Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
(*stack)->next->n += (*stack)->n;
pop(stack, line_number);
}
