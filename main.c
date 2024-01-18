#include "monty.h"
extern stack_t *stack;
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    char *opcode;
    char *arg;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';
        opcode = strtok(line, " ");
        arg = strtok(NULL, " ");

        if (opcode)
        {
            if (strcmp(opcode, "push") == 0)
            {
                if (!arg || !isdigit(arg[0]))
                {
                    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    exit(EXIT_FAILURE);
                }

                push(&stack, atoi(arg));
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(&stack, line_number);
            }
            else if (strcmp(opcode, "pint") == 0)
            {
                pint(&stack, line_number);
            }
            else if (strcmp(opcode, "pop") == 0)
            {
                pop(&stack, line_number);
            }
            else if (strcmp(opcode, "swap") == 0)
            {
                swap(&stack, line_number);
            }
            else if (strcmp(opcode, "add") == 0)
            {
                add(&stack, line_number);
            }
            else if (strcmp(opcode, "nop") == 0)
            {
                nop(&stack, line_number);
            }
            else
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
    if (line)
        free(line);

    exit(EXIT_SUCCESS);
}
