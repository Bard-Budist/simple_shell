#ifndef header_file
#define header_file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <libgen.h>
#include <signal.h>
void TokensGenator(char *dates);
size_t _getline(char *string);
void functionLs(void);
int executeCommand(char *file);
void checkCommand(char *path, char **Tokens);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void free_grid(char **grid, int height);
int checkExecutable(char *cadena);
char **getTokens(char *entrada, char **Token);
int  executeFunction(char *cadena, char **Argumens);
char *deleteSpaces(char *cadena);
#endif

