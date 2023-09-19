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
/**
 * intlen - Determine Length Of Int
 * @num: Given Int
 * Return: Length Of Int
 */
int intlen(int num)
{
int len = 0;
while (num != 0)
{
len++;
num /= 10;
}
return (len);
}
/**
 * array_rev - Reverse Array
 * @arr: Array To Reverse
 * @len: Length Of Array
 * Return: Void (Reverse Array)
 */
void array_rev(char *arr, int len)
{
int i;
char tmp;

for (i = 0; i < (len / 2); i++)
{
tmp = arr[i];
arr[i] = arr[(len - 1) - i];
arr[(len - 1) - i] = tmp;
}
}
/**
 * _strcmp -compare two strings
 *@string1:string 1
 *@string2:string 2
 *Return: 0 if Identical Otherwise How Much Diffrent
 */
int _strcmp(char *string1, char *string2)
{
int cmp = 0, i, len1, len2;
len1 = _strlen(string1);
len2 = _strlen(string2);
if (string1 == NULL || string2 == NULL)
return (1);
if (len1 != len2)
return (1);
for (i = 0; string1[i]; i++)
{
if (string1[i] != string2[i])
{
cmp = string1[i] - string2[i];
break;
}
else
continue;
}
return (cmp);
}
