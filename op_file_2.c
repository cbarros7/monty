#include "monty.h"

/**
 * search_func - Finds for the function to be executed
 * @opcode: The operation code, It could be push, pall, ...
 * @cmd: The possible value for the operation.
 * @l_num: Line number for the opcode.
 * @format: Format specifier:
 * If the value is 0 --> Stack
 * If the value is 1 --> Queue
 */
void search_func(char *opcode, char *cmd, int l_num, int format)
{
	int pos;
	int error;

	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{NULL, NULL}
	};
	/*
	 *If the first character is a #... ignore that
	 *error and continue to execute.
	 */
	if (opcode[0] == '#')
		return;

	/*Search the list for the function to be used*/
	for (error = 1, pos = 0; functions[pos].opcode != NULL; pos++)
	{
		/*Correct opcode and didn't find any error*/
		if (strcmp(opcode, functions[pos].opcode) == 0)
		{
			call_fun(functions[pos].f, opcode, cmd, l_num, format);
			error = 0;
		}
	}
	if (error == 1)
	{
		error_out(3, l_num, opcode);
	}
}

/**
 * call_fun - Calls the required function.
 * @f: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @cmd: string representing a numeric value.
 * @l_num: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func f, char *op, char *cmd, int l_num, int format)
{
	stack_t *node;
	int error;
	int i;

	error = 1;
	if (strcmp(op, "push") == 0)
	{
		/*Checks if the number is negative and moves the val ptr*/
		if (cmd != NULL && cmd[0] == '-')
		{
			cmd = cmd + 1;
			error = -1;
		}
		/*val is not a digit is the return value is 0*/
		if (cmd == NULL)
		{
			error_out(5, l_num);
		}


		for (i = 0; cmd[i] != '\0'; i++)
		{
			if (isdigit(cmd[i]) == 0)
			{
				error_out(5, l_num);
			}

		}

		/*Create new node*/
		node = new_node(atoi(cmd) * error);
		if (format == 0)
			f(&node, l_num);
		if (format == 1)
			add_to_queue(&node, l_num);
	}
	else
		f(&head, l_num);
}
