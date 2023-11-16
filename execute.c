#include "monty.h"
/**
 * process_file - reads line from the loaded file and processes it
 * @stack: the pointer to the stack
 *
 * Return: void
*/
void process_file(stack_t **stack)
{
	ssize_t read_line = 1;
	size_t line_len = 0;

	while ((read_line = getline(&data.line, &line_len, data.file)) > 0)
	{
		/* Skip empty lines */
		if (*data.line == '\n')
			continue;
		/* Skip comments */
		if (data.line[0] == '#')
			continue;
		data.line_number++; /* Increment line number */
		free(data.args); /*free args from previous assignment*/
		if (tokenize_input() < 0) /*splitting line into args*/
			continue;
		if (*data.args == NULL)
			continue;
		execute_command(stack);
	}
}
/**
 * execute_command - executes the command
 * @stack: the pointer to the stack
 *
 * Return: Always 0 for success
*/
int execute_command(stack_t **stack)
{
	instruction_t cmd[] = {
		{"push", push_stack},
		{"pall", print_stack},
		{"nop", do_nothing},
		{"pint", print_topstack},
		{"pop", pop_top},
		{"swap", swap_toptwo},
		{"add", add_toptwo},
		{NULL, NULL}
	};

	int i = 0;

	while ((cmd + i)->opcode != NULL)
	{
		if (strcmp((cmd + i)->opcode, data.args[0]) == 0)
		{
			(cmd + i)->f(stack, data.line_number);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",
			data.line_number, data.args[0]);
	return (1);
}
