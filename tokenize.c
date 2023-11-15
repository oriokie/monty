#include "monty.h"
/**
 * tokenize_input - function to split the input into tokens
 *
 * Return: 0 for success and -1 for failure
*/
int tokenize_input(void)
{
	char *token;
	size_t i = 0;
	size_t size = strlen(data.line) + 1;

	data.args = malloc(sizeof(char *) * size);
	if (data.args == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	token = strtok(data.line, DELIMITER);
	while (token != NULL)
	{
		data.args[i] = token;
		token = strtok(NULL, DELIMITER);
		i++;
	}
	data.args[i] = NULL;

	/*Check for a comment line*/
	if (i > 0 && data.args[0][0] == '#')
	{
		return (-1);
	}
	return (0);
}
