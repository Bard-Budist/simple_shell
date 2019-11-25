#include "fun.h"
/**
 * main - function that execute all command insert since screen
 *
 * Return: NULL
 **/
int main(void)
{
    char *buffer = NULL, **TokenP = NULL;
    size_t bufsize = 32, characters;
    int j = 0, k = 0;

    while (1)
    {
        buffer = calloc(bufsize, sizeof(char));
        if (buffer == NULL)
        {
            perror("Unable to allocate buffer");
            exit(1);
        }
        k = 0;
        TokenP  = calloc(80, sizeof(char));
        if (TokenP == NULL)
        {
            perror("Unable to allocate buffer");
            exit(1);
        }
        printf("HolbiPro$ ");
        characters = getline(&buffer, &bufsize, stdin);
        if (characters == (size_t)-1)
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
        {
            checkCommand(TokenP[0], TokenP);
        }
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
 * @heigh : height size of the grid
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
 * checkCommand - function that check the input whit the command in directory /bin/
 * @Tokens: double pointer of input
 **/
void checkCommand(char *string, char **Tokens)
{
	char *cadena = NULL;
	int i = 0;
	while (Tokens[i] != NULL)
		i++;
	if (i > 1)
	{
		Tokens[i - 1][strlen(Tokens[i - 1]) - 1] = '\0';
	}
	else if (i == 1)
	{
		string[strlen(string) - 1] = '\0';
	}
	Tokens[i] = NULL;
	if (string[0] != '/')
	{
		cadena = malloc((sizeof(char) * 6) + strlen(string));
		strcpy(cadena, "/bin/");
		strcat(cadena, string);
	}
	else
	{
		cadena = malloc(sizeof(char) * strlen(string));
		strcpy(cadena, string);
	}
	strcpy(Tokens[0], cadena);
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
 * @entrada : input
 *
 * Return : TokenP
 **/
char **getTokens(char *entrada, char **TokenP)
{
    char *TokenT;
    int i;
    TokenT = strtok(entrada, " ");
    i = 0;
    while (TokenT != NULL)
    {
        TokenP[i] = malloc((strlen(TokenT) + 1) * sizeof(char));
        if (TokenP[i] == NULL)
        {
            free(entrada);
            free(TokenP);
            perror("Error");
            return (NULL);
        }
        strcpy(TokenP[i], TokenT);
        TokenT = strtok(NULL, " ");
        printf("%s\n",TokenP[i]);
        i++;
    }
    free(TokenT);
    return (TokenP);
}