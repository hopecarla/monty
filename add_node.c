#include "monty.h"
/**
 * addnode - adds node to the head of the stack
 * @head: head of the stack
 * @n: represents the new value
 * Return: nothing
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *result;

	result = *head;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = result;
	new_node->prev = NULL;

	if (result)
	{
		result->prev = new_node;
	}
	*head = new_node;
}
