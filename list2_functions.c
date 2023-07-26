#include "shell.h"

/**
 * list_len - function that returns the
 * number of elements in list_t list
 *
 * @h:linked list of type list_t
 * Return:return number of nodes
 */

size_t list_len(const list_t *h)
{
	size_t len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}

/**
 * print_list - prints all the elements
 * of a linked list
 *
 * @h:linked list of type linstint
 *
 * Return:number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t sum = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : ("nil"));
		_puts("\n");
		h = h->next;
		sum++;
	}
	return (sum);
}

/**
 * node_starts_with - function that returns node whose string
 * starts with a prefix
 *
 * @node:pointer to the list_t head
 * @prefix:string to match
 * @s:the next character after prefix to match
 *
 * Return:return the matched node otherwise NULL
 */
list_t *node_starts_with(list_t *node, char *prefix, char s)
{
	char *q = NULL;

	while (node)
	{
		q = starts_with(node->str, prefix);
		if (q && ((s == -1) || (*q == s)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
