#include "monty.h"
/**
 * pchar_top - function that prints the character
 * at the top of a stack
 * @stack: the pointer to the stack
 * @line_number: the line number
 * Return: void
*/
void pchar_top(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", data.line_number);
		free_data(), free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (head->n < 0 || head->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", data.line_number);
		free_data(), free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", head->n);

}
