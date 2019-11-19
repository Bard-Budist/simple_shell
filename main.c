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
		int status = checkCommand(TokenP[0], path);
		free(TokenP);
	}
	return (0);
}

int checkCommand (char *string, char *ps)
{
	printf("Holi\n");
	char *searchpath;
    char *beg, *end;
    int stop, found;
    int len;

    if (strchr(string, '/') != NULL) {
	  if (realpath(string, ps) == NULL)
	  return 0;
	  return  executeCommand(ps);
    }

     searchpath = getenv("PATH");
	 printf("Teste");
     if (searchpath == NULL)
	 	return 0;
     if (strlen(searchpath) <= 0)
	 	return 0;

    /* beg = searchpath;
	stop = 0; found = 0;
	do {
		end = strtok(beg, ":");
		if (end == NULL)
		{
			strncpy(ps, beg, PATH_MAX);
			len = strlen(ps);
			stop = 1;
		}
		else
		{
			strncpy(ps, beg, end - beg);
			ps[end - beg] = '\0';
			len = end - beg;
		}
		strncat(ps, "/", 1);
		strncat(end,path, PATH_MAX - len);
		printf("PS= %s\nEND= %s\n", ps, end);
		if (!stop) beg = end + 1;
		end = strtok(NULL, ":");
	} while (!stop && !found);
	return found; */
	beg =  malloc(1024);
	puts(searchpath);
	strcpy(beg, searchpath);
	if (beg == NULL)
	beg = searchpath;
	stop = 0; found = 0;
	do {
		end = strchr(beg, ':');
		if (end == NULL) {
			stop = 1;
			strncpy(ps, beg, PATH_MAX);
			len = strlen(ps);
		} else {
			strncpy(ps, beg, end - beg);
			ps[end - beg] = '\0';
			len = end - beg;
		}
		if (ps[len - 1] != '/') strncat(ps, "/", 1);
		strncat(ps, string, PATH_MAX - len);
		puts(ps);
		found = executeCommand(ps);
		printf("%i", found);
		if (!stop) beg = end + 1;
	} while (!stop && !found);
    return found;
}


int executeCommand(char *file)
{
	int result;
	struct stat statinfo;

	result = stat(file, &statinfo);
	if (result < 0) return 0;
	if (!S_ISREG(statinfo.st_mode)) return 0;

	if (statinfo.st_uid == geteuid()) return statinfo.st_mode & S_IXUSR;
	if (statinfo.st_gid == getegid()) return statinfo.st_mode & S_IXGRP;
	return statinfo.st_mode & S_IXOTH;

}

