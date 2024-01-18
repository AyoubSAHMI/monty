#include "monty.h"
extern stack_t *stack;
/**
* pop - removes the top element of the stack
* @stack: the stack we're using
* @line_number: the line concerned
* Return: void
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t temp = **stack;
if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
temp = *stack;
*stack = (*stack)->next;
if (*stack)
(*stack)->prev = NULL;
}
