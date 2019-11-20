#include "fun.h"
/**
 *
 *
 *
 *
 *
 *
*/
int  executeFunction(char *cadena, char **Argumens)
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
	}
	else
	{
		waitpid(child, &status, 0);
	}
	return (0);
}
