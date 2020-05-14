#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry to the program
 * @argc: Number of command line arguments.
 * @argv: An array containing the arguments.
 * Return: Always Zero.
 */
int main(int argc, char **argv)
{
	/*argc must be 2*/
	if (argc < 2 || argc > 2)
		error_out(1);
	open_file(argv[1]);
	/*Free memory*/
	free_nodes();
	return (0);
}
