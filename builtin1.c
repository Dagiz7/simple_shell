#include "shell.h"

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

int unset_alias(info_t *info, char *str)
{
	char *pa, c;
	int ret;

	pa = _strchr(str, '=');
	if (!pa)
		return (1);
	c = *pa;
	*pa = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*pa = c;
	return (ret);
}

int set_alias(info_t *info, char *str)
{
	char *pa;
	pa = _strchr(str, '=');
	if (!pa)return (1);
	if (!*++pa)return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

int print_alias(list_t *node)
{
	char *pa = NULL, *b = NULL;

	if (node)
	{
		pa = _strchr(node->str, '=');
b = node->str
		while( b <= pa)
			{
_putchar(*b);
b++
}
		_putchar('\'');
		_puts(pa + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

int _myalias(info_t *info)
{
	int k = 1;
	char *pa = NULL;
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
	while ( info->argv[k])
	{
		pa = _strchr(info->argv[k], '=');
		if (pa)
			set_alias(info, info->argv[k]);
		else
			print_alias(node_starts_with(info->alias, info->argv[k], '='));
k++
	}

	return (0);
}
