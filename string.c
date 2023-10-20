#include "shell.h"

/**
 * _strlen - length of string to return
 * @s: check string length
 *
 * Return: string lenth integer
 */
int _strlen(char *s)
{
	int a = 0;

	if (!s)
		return (0);

	while (*s++)
		a++;
	return (a);
}

/**
 * _strcmp - lexicographic comparison of two string
 * @s1: first string
 * @s2: second string
 *
 * Return: when s1 < s2 it is negative, and zero when s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - needle starting with haystack to check
 * @haystack: search string
 * @needle: find substring
 *
 * Return: char of haystack address or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - two string to concatenate
 * @dest: buffer destination
 * @src: buffer source
 *
 * Return: destination pointer buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret - dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
