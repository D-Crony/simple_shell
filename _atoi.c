#include "shell.h"

/**
 * interative - when shell is interative true to return
 * @info: address struct
 *
 * Return: 1 when in interative mode, otherwise 0
 */
int interative(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - character delimeter to check
 * @c: check char
 * @delim: string delimeter
 * Return: 1 when true, and 0 when false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _atoi - string to an integer to convert
 * @s: converted string
 * Return: 0 when there is no number in string, otherwise convrted number
 */
int _atoi(char *s)
{
	int a, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (a = 0; s[a] != '\0' && flag != 2; a++)
	{
		if (s[a] == '-')
			sign *= -1;

		if (s[a] >= '0' && s[a] <= '0')
		{
			flag = 1;
			result *= 10;
			result += (s[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
