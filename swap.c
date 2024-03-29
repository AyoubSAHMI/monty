#include "monty.h"
extern stack_t *stack;
/**
* swap - swaps the top two elements of the stack
* @stack: the stack we're using
* @line_number: line we swap
* Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
temp = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp;
}
