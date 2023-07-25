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
		new_head->str = strdup(str);
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
	list_t *new;
	list_t *temp = *head;
	unsigned int len = 0;

	while (str[len])
	{
		len++;
	}

	new = malloc(sizeof(list_t));
	if (!new)
	{
		return (NULL);
	}

	new->str = strdup(str);
	new->len = len;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	else
	{
		while (temp->next)
		{
		temp = temp->next;
		temp->next = new;
		return (new);
		}
	}
	return (new);
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
