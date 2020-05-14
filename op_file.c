#include "monty.h"
/**
 * open_file - Opens a file.
 * @file_name: String with the name of the file.
 */
void open_file(char *file_name)
{
	int file_check;
	FILE *fd;

	if (file_name == NULL)
		error_out(2, file_name);

	/*Checks if the file exists*/
	file_check = access(file_name, R_OK);
	if (file_check == -1)
		error_out(2, file_name);

	fd = fopen(file_name, "r");
	if (fd == NULL)
		error_out(2, file_name);
	/*errors should be handled inside this function*/
	read_file(fd);
	/*might need to check for errors on closing a file.*/
	fclose(fd);
}

/**
 * read_file - Reads the content of a file line by line.
 * @fd: Pointer to a file descriptor of an open file
 */
void read_file(FILE *fd)
{
	int number_line;
	int format = 0;
	char *lineprt = NULL;
	size_t n = 0;

	if (fd == NULL)
		error_out(2, "file_name");

	/*Read line by line*/
	for (number_line = 1; getline(&lineprt, &n, fd) != EOF; number_line++)
	{
		format = interpret_line(lineprt, number_line, format);
	}
	free(lineprt);
}

/**
 * interpret_line - Separates each line into tokens to determine
 * which function to call.
 * @lineptr: String representing a line in a file.
 * @line_number: Line number for the opcode.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int interpret_line(char *lineptr, int line_number, int format)
{
	char *opcode;
	char *cmd;

	if (lineptr == NULL)
		error_out(4);

	/*Read command line by line*/
	opcode = strtok(lineptr, " \t\n");

	/*hanlding blank lines*/
	if (opcode == NULL)
		return (format);
	cmd = strtok(NULL, " \t\n");

	/*compare two strings*/
	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);

	search_func(opcode, cmd, line_number, format);
	return (format);
}

/**
 * search_func - Finds the appropite function to run the opcode instructions.
 * @opcode: The operation code, It could be push, pall, ...
 * @cmd: The possible value for the operation.
 * @l_num: Line number for the opcode.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void search_func(char *opcode, char *cmd, int l_num, int format)
{
	int pos;
	int error;

	instruction_t functions[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{NULL, NULL}
	};

	/*
	*If the first character is a #... ignore that
	*error and continue to execute.
	*/
	if (opcode[0] == '#')
		return;

	/*Search the list for the function to be used*/
	for (pos = 0; functions[pos].opcode != NULL; pos++)
	{
		/*Correct opcode and didn't find any error*/
		if (strcmp(opcode, functions[pos].opcode) == 0)
		{
			call_fun(functions[pos].f, opcode, cmd, l_num, format);
			error = 0;
		}
	}
	if (error == 1)
		error_out(3, l_num, opcode);
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
			error_out(5, l_num);
		for (i = 0; cmd[i] != '\0'; i++)
		{
			if (isdigit(cmd[i]) == 0)
				error_out(5, l_num); /*cambia valor error 2*/
		}

		/*Add new node*/
		node = new_node(atoi(cmd) * error);
		if (format == 0)
			f(&node, l_num);
	}
	else
		f(&head, l_num);
}

