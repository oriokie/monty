#include "monty.h"
/**
 * rotate1 - function that rotates the stack to the top
 * @stack: the pointer to the stack
 * @line_number: the line number
 * Return: void
*/
void rotate1(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *first, *second, *last;

	first = *stack;
	second = first->next;
	last = first;

	/*Finding the last element*/
	while (last->next != NULL)
		last = last->next;

	last->next = first;
	first->next = NULL;
	*stack = second;
}
