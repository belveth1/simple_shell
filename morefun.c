#include "main.h"
/**
 * _isalpha - check is it alphabtic.
 *@a: Char.
 * Return: return 1 if true 0 if not true.
 */
int _isalpha(int a)
{
if (((a >= 97) && (a <= 122)) || ((a >= 65) && (a <= 90)))
{
return (1);
}
else
{
return (0);
}
}

/**
 * _itoa - turn the integer to char.
 * @intn: Int To turn
 * Return: character to pointer
 */
char *_itoa(unsigned int intn)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(intn);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (intn / 10)
	{
		s[i] = (intn % 10) + '0';
		intn /= 10;
		i++;
	}
	s[i] = (intn % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}
