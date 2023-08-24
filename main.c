#include "minishell.h"
/**
 * main - entry point
 *
 * @argc: number of arguments given to the program
 * @argv: arguments list
 *
 * Return: returns the value of the last executed command
 */
int main(int argc, char **argv)
{
Bool status = true;
	char **cmdargs;
	char *cmdline = NULL;
	char prompt[] = "(hsh) ";	
	name = (argv[0] != NULL) ? argv[0] : NULL;

	for(;status;)
	{
		write(1, prompt, strlen(prompt));
		cmdline = get_user_input();
	}
	return (0);
}
