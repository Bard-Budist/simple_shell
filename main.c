#include "fun.h"


	int main(void)
	{
		char path[PATH_MAX+1];
		char *buffer, *TokenT, *callBand;
		char **TokenP;
		size_t bufsize = 32;
		size_t characters;
		int i = 0;

		int result;
		struct stat statinfo;


		buffer = malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}
		while (1)
		{
			TokenP = malloc(sizeof(char *) * bufsize);
			printf("*_*$> ");

			characters = getline(&buffer, &bufsize, stdin);
			if (characters == (size_t)-1)
			{
				free(TokenP);
				free(buffer);
				printf("\nBye\n");
				break;
			}
			TokenT = strtok(buffer, " ");
			while (TokenT != NULL)
			{
				TokenP[i] = TokenT;
				TokenT = strtok(NULL, " ");
				i++;
			}
			int status = checkCommand(TokenP[0]);
			if (status == 1)
			{
				printf("Is executable");
			}
			else
			{
				printf("No is executable");
			}
			free(TokenP);
		}
		return (0);
	}

	int checkCommand (char *string)
	{
		int i = 0;
		char cadena[1024];
		string[strlen(string) - 1] = '\0';
		strcpy(cadena, "/bin/");
		strcat(cadena,string);
		printf("%s\n", cadena);
		if (access(cadena, F_OK|X_OK) == 0)
		{
			return(1);
		}
		return (0);
	}


