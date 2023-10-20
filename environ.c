#include "shell.h"

/**
 * _myenv - current environment to print
 * @info: potential argument containing structure to maintain
 * function prototype
 * Return: 0(always)
 */
int _myenv(info_t *info)
{
	print_list_str(info->new);
	return (0);
}

/**
 * _getenv - value of environ variable
 * @info: potential argument containing structure to maintain
 * @name: name var env
 *
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *a;

	while (node)
	{
		a = starts_with(node->str, name);
		if (a && *a)
			return (a);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - new environment variable to initialise or modify
 * the one that exist
 * @info: potential argument containing structure to maintain
 * function prototype
 * Return: 0(always)
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("incorrect number of argument\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - environment variable to remove
 * @info: potential argument containing structure to maintain
 * prototype function
 * Return: 0(always)
 */
int _myunsetenv(info_t *info)
{
	int a;

	if (info->argv == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (a = 1; a <= info->argc; a++)
		_unsetenv(info, info->argv[a]);

	return (0);
}

/**
 * populate_env_list - linked list populate env
 * @info: potential argument containing structure to maintain
 * prototype function
 * Return: 0(always)
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a], a++)
		add_node_end(&node, environ[a], 0);
	info->new = node;
	return (0);
}
