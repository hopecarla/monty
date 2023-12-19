#include "monty.h"

void free_stack(stack_t *head);

/**
 * add - adds the top two elements of the stack
 * @head: double pointer to the head of the stack
 * @counter: line number in monty byte code file
 * Return: nothing
 */
void add(stack_t **head, unsigned int counter)
{
	stack_t *h, *temp;
	int len = 0, result;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->next;
	result = h->n + temp->n;

	temp->n = result;
	*head = temp->next;
	free(h);
}
