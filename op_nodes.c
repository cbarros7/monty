#include "monty.h"

/**
 * nop - does nothing
 * @stack: top of the stack
 * @line_num: current line number
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)*stack;
	(void)line_num;
}
