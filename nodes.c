#include "monty.h"

/**
 * new_node - Creates new node
 * @n: Number to go inside the node.
 * Return: new node
 */
stack_t *new_node(int n)
{
	stack_t *node;

	/*Allocated memory*/
	node = malloc(sizeof(stack_t));
	/*Handle error*/
	if (node == NULL)
		error_out(4);
	node->prev = NULL;
	node->next = NULL;
	/*Assign data*/
	node->n = n;
	return (node);
}

/**
 * free_nodes - free up memory in the stack
 * return : void
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

