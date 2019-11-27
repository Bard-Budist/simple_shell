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
/**
 * deleteSpaces - function that delte spaces in the string
 * @cadena: pointer of input
 *
 * Return: Always retorno
 **/
char *deleteSpaces(char *cadena)
{
	int i = 0, j = 0;
	char copy[1024], *retorno;

	for (i = 0; i < len; i++)
	{
		if (cadena[i] != ' ' && cadena[i] != '\n')
		{
			copy[j] = cadena[i];
			j++;
			if (cadena[i + 1] == ' ')
			{
				copy[j] = ' ';
				i++;
				j++;
			}
		}
	}
	copy[j] = '\0';
	retorno = malloc(sizeof(char) * strlen((copy) + 1));
	strcpy(retorno, copy);
	free(cadena);
	return (retorno);
}
