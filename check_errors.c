#include "monty.h"
/**
 * error_out - Prints error messages
 * @error_code: The error codes are the following
 */
void error_out(int error_code, ...)
{
	va_list ag;
	char *opcode_error;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			opcode_error = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, opcode_error);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * others_error - handles errors.
 * @error_code: The error codes are the following:
 */
void others_error(int error_code, ...)
{
	va_list ag;
	char *opcode_error;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			opcode_error = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, opcode_error);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

