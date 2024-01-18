#include "monty.h"
#define MAX_LINE_LENGTH 1024

/* Global variable for the stack */
stack_t *stack = NULL;

int main(int argc, char *argv[])
{
    FILE *file;
    char line[MAX_LINE_LENGTH];
    size_t len;
    unsigned int line_number = 0;

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

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *opcode, *arg;

        line_number++;

        /* Remove newline character from the end of the line */
        len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';

        /* Tokenize the line to extract opcode and argument */
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
                pall(&stack);
            }
            /* Add other opcode cases as needed */
            else
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
    exit(EXIT_SUCCESS);
}
