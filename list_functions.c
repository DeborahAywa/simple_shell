#shell.h

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
 * free_list - free list_t list
 * @head:pointer to list_t to be freed
 *
 */

void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
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
	listint_t *temp = *head;
	listint_t *current = NULL;
	unsigned int p = 0;

	if (*head == NULL)
	{
		return (0);
	}
	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	while (p < index - 1)
	{
		if (!temp || !(temp->next))
		{
			return (-1);
		}
		temp = temp->next;
		p++;
	}
	current = temp->next;
	temp->next = current->next;
	free(current);
	return (1);
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
