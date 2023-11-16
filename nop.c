#include "monty.h"
/**
 * do_nothing - function that does not do anything
 * @stack: the pointer to the stack (unused)
 * @line_number: the line number (unused)
*/
void do_nothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
    free_stack(stack);
}
