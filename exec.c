#include "monty.h"

void stack(stack_t **head, unsigned int counter);

/**
 * execute - executes the opcode
 * @stack: head linked list -stack
 * @counter: line counter
 * @file: pointer to monty file
 * @content: line content
 * Return: nothing
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t ops[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op == NULL || op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");

	if (bus.arg == NULL && strcmp(op, "push") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	while (ops[i].opcode)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
	fclose(file);
	free(content);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}


