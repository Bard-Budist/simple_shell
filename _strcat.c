#include "fun.h"
/**
 * _strcat - Concat string
 * @dest: Destino
 * @src: Recurso
 *
 * Return: String concat
*/
char *_strcat(char *dest, char *src)
{
	int c = 0, c2 = 0, i;
	char *T = src;
	char *P = dest;

	while (*P)
	{
		c++;
		P++;
	}
	while (*T)
	{
		c2++;
		T++;
	}
	for (i = 0; i < c2; i++)
	{
		dest[c] = src[i];
		c++;
	}
	dest[c] = '\0';
	return (dest);
}
