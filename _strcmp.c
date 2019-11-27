#include "fun.h"
/**
 * _strcmp - Compare string
 * @s1: String 1
 * @s2: String 2
 * Return: Return value
*/
int _strcmp(char *s1, char *s2)
{
int i = 0, band;
int n1 = 0, n2 = 0;

while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
	i++;
n1 = s1[i] + 0;
n2 = s2[i] + 0;
band = n1 - n2;
return (band);
}
