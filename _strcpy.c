#include "fun.h"
/**
 * _strcpy - Copy string
 * @dest: Destino
 * @src: Recurso
 * Return: Char
*/
char *_strcpy(char *dest, char *src)
{
	char *t = src;
	int len = 0, i;

	while (*t != '\0')
	{
	len++;
	t++;
	}
	for (i = 0; i <= len; i++)
	{
	dest[i] = src[i];
	}
	return (dest);
}
