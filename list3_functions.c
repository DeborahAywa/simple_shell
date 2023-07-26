#include "shell.h"

/**
 * add_node - function that adds a node at the start of the list
 *
 * @head:address of pointer to head node
 * @str:string of field of node
 * @num:node index used by history
 *
 * Return:size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - function that adds new
 * node at the end of a list_t list
 * @head:double pointer to the list list_t
 * @str:string to be put in the new node
 *
 * Return:the address of the new element
 * on success and NULL on failure
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);
	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - function that prints only the string element
 * of a list_t linked list
 *
 * @h:pointer to the first node
 *
 * Return:size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : ("nil"));
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}
