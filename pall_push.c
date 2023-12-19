#include "monty.h"

void addqueue(stack_t **head, int value);

/**
 * push - pushes an element onto the stack
 * @head: head of the stack
 * @counter: line number
 * Return: nothing
 */
void push(stack_t **head, unsigned int counter)
{
	int i, j = 0;

	if (bus.arg == NULL || bus.arg[0] == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (bus.arg[0] == '-')
		j++;
	while (bus.arg[j] != '\0')
	{
		if (!isdigit(bus.arg[j]))
			{
				fprintf(stderr, "L%d: usage: pus integer\n", counter);
				fclose(bus.file);
				free(bus.content);
				free_stack(*head);
				exit(EXIT_FAILURE);
			}
			j++;
	}
	i = atoi(bus.arg);

	if (bus.lifi == 0)
	addnode(head, i);
	else
	addqueue(head, i);
	}

/**
 * pall - prints all the values on the stack
 * @head: head of the stack
 * @counter: not used
 * Return: nothing
 */
void pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void) counter;

	h = *head;

	while (h)
	{
		printf("%d\n", h->i);
		h = h->next;
	}
}
