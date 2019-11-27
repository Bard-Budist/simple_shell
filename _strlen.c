#include "fun.h"
/**
 * _strlen - Print length of String
 * @s: Parameter of string
 *
 * Return: Length of String
 *
*/
int _strlen(char *s)
{
int len = 0;

while (*s != '\0')
{
s++;
len++;
}
return (len);
}
