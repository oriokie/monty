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
		data.line_number++; /* Increment line number */
		/* Skip empty lines */
		if (*data.line == '\n')
			continue;
		/* Skip comments */
		if (data.line[0] == '#')
			continue;
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
		{"sub", sub_toptwo},
		{"div", div_toptwo},
		{"mul", mul_toptwo},
		{"mod", mod_toptwo},
		{"pchar", pchar_top},
		{"pstr", print_char},
		{"rotl", rotate1},
		{"rotr", rotate2},
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
	free_data(), free_stack(stack);
	exit(EXIT_FAILURE);
}
