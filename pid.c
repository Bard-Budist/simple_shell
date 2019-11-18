#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/**
 * main - function that print where is the process
 * Return: Always 0
 **/
int main(void)
{
pid_t pid = getpid();

printf("%i\n", pid);
return (0);
}
