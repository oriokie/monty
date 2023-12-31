#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#define DELIMITER " \n\t\r\a"

/*Critical Headers*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>


/*Provided Data structures*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**created typedef*/

/**
 * struct global_s - global variables
 * @line_number: the line number
 * @file: the file
 * @filename: the file name
 * @line: the line
 * @args: the arguments
 *
 * Description: global variables
 * for stack, queues, LIFO, FIFO
*/

typedef struct global_s
{
	int line_number;
	FILE *file;
	char *filename;
	char *line;
	char **args;
} global_t;

/*Global variables*/
extern global_t data;


/* Prototypes */
void process_file(stack_t **stack);
int execute_command(stack_t **stack);
void free_stack(stack_t **stack);
void free_data(void);
int tokenize_input(void);
void print_stack(stack_t **stack,
		unsigned int line_number __attribute__((unused)));
void push_stack(stack_t **stack,
		unsigned int line_number __attribute__((unused)));
void do_nothing(stack_t **stack, unsigned int line_number);
void print_topstack(stack_t **stack,
		unsigned int line_number __attribute__((unused)));
void pop_top(stack_t **stack,
	unsigned int line_number __attribute__((unused)));
void swap_toptwo(stack_t **stack,
	unsigned int line_number __attribute__((unused)));
void add_toptwo(stack_t **stack, unsigned int line_number);
void sub_toptwo(stack_t **stack, unsigned int line_number);
void div_toptwo(stack_t **stack,
	unsigned int line_number __attribute__((unused)));
void mul_toptwo(stack_t **stack,
	unsigned int line_number __attribute__((unused)));
void mod_toptwo(stack_t **stack,
		unsigned int line_number __attribute__((unused)));
void pchar_top(stack_t **stack,
		unsigned int line_number __attribute__((unused)));
void print_char(stack_t **stack,
		unsigned int line_number __attribute__((unused)));
void rotate1(stack_t **stack,
		unsigned int line_number __attribute__((unused)));
void rotate2(stack_t **stack,
		unsigned int line_number __attribute__((unused)));

#endif/* MONTY_H */
