#include "monty.h"
extern stack_t *stack;
/**
* pint - prints the value at the top of the stack, followed by a new line
* @stack: the stack we're using
* @line_number: the lune we can't print
* Return: void
*/
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
