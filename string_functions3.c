#include "main.h"
/**
 * _atoi - convert to a int
 * @str:string
 * Return:int
*/
int _atoi(char *str)
{
int result = 0;
int sign = 1;

if (str[0] == '-')
{
sign = -1;

}

while (*str != '\0')
{
result = result * 10 + (*str - '0');
str++;
}
return (result *sign);
}
