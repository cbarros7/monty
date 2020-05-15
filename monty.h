#ifndef __MONTY__H
#define __MONTY__H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

/*Type for opcode functions*/
typedef void (*op_func)(stack_t **, unsigned int);


/*File operations*/
void open_file(char *);
void read_file(FILE *);
int len_chars(FILE *);
int interpret_line(char *, int, int);
void search_func(char *, char *, int, int);

/*Stack operations*/
stack_t *new_node(int n);
void free_nodes(void);
/*print stack*/
void pall(stack_t **, unsigned int);
/*add stack*/
void push(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);
/*print top*/
void pint(stack_t **, unsigned int);
/*pop top*/
void pop(stack_t **, unsigned int);

void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);


/*Error hanlding*/
void error_out(unsigned int error_code, ...);
void others_error(unsigned int error_code, ...);
void add(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void divide(stack_t **stack, unsigned int line_num);

#endif /* MONTHY */
