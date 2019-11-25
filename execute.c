#include "fun.h"
/**
 * executeFunction - function that execute the command since screen
 * @cadena: pointer of input
 * @Argumens: double pointer of input
 *
 * Return: Always0
*/
int executeFunction(char *cadena, char **Argumens)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (checkExecutable(cadena) == 1)
		{
			execve(cadena, Argumens, NULL);
		}
		else
		{
			free(cadena);
			perror("./shell");
			exit(127);
		}
	}
	else
	{
		waitpid(child, &status, 0);
	}
	return (0);
}
