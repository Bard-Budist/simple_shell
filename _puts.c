#include "fun.h"
/**
 * _puts - Print the string
 * @str: Parameter String
 *
 *
 *
*/
void _puts(char *str)
{
while (*str != '\0')
{
_putchar(*str);
str++;
}
}
