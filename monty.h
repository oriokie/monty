#define _GNU_SOURCE
#ifndef MONTY_H
#define MONTY_H
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

typedef struct global_s{
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



#endif /* MONTY_H */
