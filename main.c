#include "monty.h"

global_t data = {0, NULL, NULL, NULL, NULL};

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: EXIT_FAILURE or EXIT_SUCCESS
*/
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		data.filename = argv[1];
		data.file = fopen(data.filename, "r");
		if (data.file == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", data.filename);
			exit(EXIT_FAILURE);
		}
		process_file(&stack); /* Process file and update the stack */
		free_stack(&stack); /* Free the stack */
		free_data(); /* Free the data */
	}
	return (EXIT_SUCCESS);
}
