#include "fun.h"
/**
 * _strdup - str
 * @str: String paramter
 * Return: Char
 *
 *
*/
char *_strdup(char *str)
{
	char *p;
	unsigned int a = 0, i = 0;

	if (str != 0)
	{
		while (str[a] != '\0')
		a++;
		a++;
		p = malloc(a * sizeof(char));
		if (p == 0)
			return (NULL);
		while (i < a)
		{
		p[i] = str[i];
		i++;
		}
		return (p);
	}
	return (NULL);
}
