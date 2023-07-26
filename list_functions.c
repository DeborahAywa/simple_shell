#include "shell.h"

/**
 * print_list_str - function that only prints the str
 * of a linked list
 * @h:pointer to the list_t list to be print
 *
 * Return:number of nodes to be printed
 */
size_t print_list_str(const list_t *h)
{
	size_t p = 0;

	while (h)
	{
		_puts(h->str ? h->str : ("nil"));
		_puts("\n");
		h = h->next;
		p++;
	}
	return (p);
}

/**
 * free_list -function that frees list_t list
 * @head_ptr:pointer to list_t to be freed
 *
 */

void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

/**
 * delete_node_at_index - function to delete
 * node at a specific index in linked list
 *
 * @head:pointer to first element of linked list
 * @index:index of node to delete
 *
 i* Return:1 on success and 0 on failure
 */

int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head | !*head)
		return (0);
	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * list_to_string - function that returns an array of list_t strings
 *
 * @head: pointer to the first node
 *
 * Return: returns an array of strings
 */
char **list_to_string(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **result;
	char *str;

	if (!head || !i)
		return (NULL);
	result = malloc(sizeof(char *) * (i + 1));
	if (!result)
		return (NULL);
	for (i = 0; node; node = node->next; i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(result[j]);
			free(result);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		result[i] = str;
	}
	result[i] = NULL;
	return (result);
}

/**
 * get_node_index - function that gets the index of a node
 *
 * @head:pointer to the list
 * @node:pointer to node
 *
 * Return:index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t j = 0;

	while (head)
	{
		if (head == node)
			return (j);
		head = head->next;
		j++;
	}
	return (-1);
}
