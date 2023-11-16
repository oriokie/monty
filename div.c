#include "monty.h"
/**
 * div_toptwo - function that divides the top two elements of
 * the stack
 * @stack: the pointer to the stack
 * @line_number: the line number (unused)
 * Return: void
*/
void div_toptwo(stack_t **stack,
	unsigned int line_number __attribute__((unused)))
{
	int result = 0;
	int first, second;
	stack_t *head = *stack;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", data.line_number);
		free_data(), free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", data.line_number);
		free_data(), free_stack(stack);
		exit(EXIT_FAILURE);
	}
	first = head->n;
	second = head->next->n;
	result = second / first;
	head->next->n = result;
	head->next->prev = NULL;
	*stack = head->next;
	free(head);
}
