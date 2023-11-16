#include "monty.h"
/**
 * rotate2 - function that rotates the stack to the bottom
 * @stack: the pointer to the stack
 * @line_number: the line number
 * Return: void
*/
void rotate2(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *first, *second_last, *last;

	first = *stack;
	second_last = NULL;
	last = first;

	/*Finding the last element*/
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->next = first;
	*stack = last;
}
