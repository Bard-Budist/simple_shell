#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *buffer;
    
    size_t bufsize = 32;
    int characters;
    char *token;
    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }
    while (1)
    {
        /*Colors*/
        printf("\033[91m");
        printf("$ ");
        /*End color*/
        printf("\033[0m");
        characters = getline(&buffer,&bufsize,stdin);
        token = strtok(buffer, " ");
        while (token != NULL)
        {
            printf("%s\n", token);
            token = strtok(NULL, " ");
        }
        if (characters == -1)
        {
            break;
        }
    }
    free(buffer);
    return(0);
}