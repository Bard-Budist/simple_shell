#ifndef header_file
#define header_file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/stat.h>
#include <libgen.h>
void TokensGenator(char *dates);
void free_grid(char **grid);
size_t _getline(char *string);
void functionLs();
int executeCommand(char *file);
	int checkCommand (char *path);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
#endif
