#include "fun.h"
/**
 * main - function that execute all command insert since screen
 *
 * Return: NULL
 **/
int main(void)
{
	char *buffer = NULL, **TokenP = NULL;
	size_t bufsize = 80, characters;
	int j = 0, k = 0;

	while (1)
	{
		buffer = malloc(sizeof(char) * bufsize);
		if (buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}
		k = 0;
		TokenP  = malloc(sizeof(char) * 80);
		if (TokenP == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}
		if (isatty(STDIN_FILENO) == 1)
			_puts("HolbiPro$ ");
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == (size_t)-1 || _strcmp(buffer, "exit\n") == 0)
		{
			j = 0;
			while (TokenP[j] != NULL)
				j++;
			free_grid(TokenP, j);
			free(buffer);
			break;
		}
		TokenP = getTokens(buffer, TokenP);
		if (TokenP != NULL)
			checkCommand(TokenP[0], TokenP);
		while (TokenP[k] != NULL)
			k++;
		free_grid(TokenP, k);
		free(buffer);
	}
	return (0);
}
/**
 * free_grid - function that free the double pointer
 * @grid : double pointer for the Tokens
 * @height : height size of the grid
 **/
void free_grid(char **grid, int height)
{
	int i = 0;

	for (i = 0; i < height; i++)
		if (grid[i] != NULL)
		{
			free(grid[i]);
		}
	free(grid);
}
/**
 * checkCommand - check the input whit the command in directory /bin/
 * @Tokens: double pointer of input
 * @string: Pointer of input
 **/
void checkCommand(char *string, char **Tokens)
{
	char *cadena = NULL;
	int i = 0;

	while (Tokens[i] != NULL)
		i++;
	if (i > 1)
	{
		Tokens[i - 1][_strlen(Tokens[i - 1]) - 1] = '\0';
	}
	else if (i == 1)
	{
		string[_strlen(string) - 1] = '\0';
	}
	Tokens[i] = NULL;
	if (string[0] != '/')
	{
		cadena = malloc((sizeof(char) * 6) + _strlen(string));
		_strcpy(cadena, "/bin/");
		_strcat(cadena, string);
	}
	else
	{
		cadena = malloc(sizeof(char) * _strlen(string) + 1);
		_strcpy(cadena, string);
	}
	free(Tokens[0]);
	Tokens[0] = malloc(sizeof(char) * _strlen(cadena) + 1);
	if (Tokens[0] == NULL)
	{
		perror("Unable memory llocation");
		exit(1);
	}
	_strcpy(Tokens[0], cadena);
	free(cadena);
	executeFunction(Tokens[0], Tokens);
}
/**
 * checkExecutable - function that execute the command scince screen
 * @cadena: string of input
 *
 * Return: 1 if cadena == 0 else 0
 **/
int checkExecutable(char *cadena)
{
	if (access(cadena, F_OK | X_OK) == 0)
	{
		return (1);
	}
	return (0);
}
/**
 * getTokens - function that generate Tokens
 * @entrada : pointer of input
 * @TokenP: double pointer of input
 * Return: Always TokenP
 **/
char **getTokens(char *entrada, char **TokenP)
{
	char *TokenT;
	int i;

	TokenT = strtok(entrada, " ");
	i = 0;
	while (TokenT != NULL)
	{
		TokenP[i] = malloc((_strlen(TokenT) + 1) * sizeof(char));
		if (TokenP[i] == NULL)
		{
			free(entrada);
			free(TokenP);
			perror("Error");
			return (NULL);
		}
		_strcpy(TokenP[i], TokenT);
		TokenT = strtok(NULL, " ");
		i++;
	}
	free(TokenT);
	return (TokenP);
}
