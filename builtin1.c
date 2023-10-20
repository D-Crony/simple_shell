#include "shell.h"

/**
 * _myhistory - history list display,proceed command line with
 * number line
 * @info: potential argument with structure to maintain
 * fuction prototype
 * Return: 0 (always)
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - string alias to set
 * @info: struct parameter
 * @str: alias string
 *
 * Return: 0 (success), 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *a, c;
	int ret;

	a = _strchr(str, '-');
	if (!a)
		return (1);
	c = *a;
	*a = 0;
	ret = delete_node_at_index(&(info->alias), get_node_index(info->alias,
				node_starts_with(info->alias, str, -1)));
	*a = c;
	return (ret);
}

/**
 * set_alias - string alias to set
 * @info: struct parameter
 * @str: alias string
 *
 * Return: 0 (success), 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *a;

	a = _strchr(str, '-');
	if (!a)
		return (1);
	if (!*++a)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - alias string to print
 * @node: alias node
 *
 * Return: 0 (success), 1 on error
 */
int print_alias(list_t *node)
{
	char *a = NULL, *b = NULL;

	if (node)
	{
		a = _strchr(node->str, '-');
		for (b = node->str; b <= a; b++)
		_putchar('\'');
		_puts(p + 1);
		return (0);
	}
	return (1);
}

/**
 * _myalias - alias builtin mimic
 * @info: potential argument containing structure to maintain
 * prototype function
 * Return: 0 (always)
 */
int _myalias(info_t *info)
{
	int c = 0;
	char *a = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (c = 1; info->argv[c]; c++)
	{
		a = _strchr(info->argv[c], '-');
		if (a)
			set_alias(info, info->argv[c]);
		else
			print_alias(node_starts_with(info->alias,
						info->argv[c], '-'));
	}

	return (0);
}
