#include "monty.h"
/**
 * print_char - function that prints the character/string
 * based on the ascii value provided
 * @stack: the pointer to the stack
 * @line_number: the line number
 * Return: void
*/
void print_char(stack_t **stack,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *head = *stack;

	while (head != NULL)
	{
		if (head->n < 32 || head->n > 127)
			break;
		printf("%c", head->n);
		head = head->next;
	}
	printf("\n");
}
