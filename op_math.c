#include "monty.h"


/**
 * sub - Substrac the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void sub(stack_t **stack, unsigned int line_num)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		others_error(8, line_num, "sub");

	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divide - Division the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */

void divide(stack_t **stack, unsigned int line_num)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		others_error(8, line_num, "div");

	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

