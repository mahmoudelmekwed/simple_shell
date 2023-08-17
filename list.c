#include "shell.h"

/**
 * add_node1 - add node at the begining of list
 * @hnode: pointer head node
 * @str: string
 * @index: node index
 *
 * Return: size
 */
list_t *add_node1(list_t **hnode, const char *str, int index)
{
	list_t *new_hnode;

	if (!hnode)
		return (NULL);
	new_hnode = malloc(sizeof(list_t));
	if (!new_hnode)
		return (NULL);
	_memset1((void *)new_hnode, 0, sizeof(list_t));
	new_hnode->num = index;
	if (str)
	{
		new_hnode->str = _strdup1(str);
		if (!new_hnode->str)
		{
			free(new_hnode);
			return (NULL);
		}
	}
	new_hnode->next = *hnode;
	*hnode = new_hnode;
	return (new_hnode);
}

/**
 * add_node_end1 - add node at end of linked list
 * @hnode: head node
 * @str: string
 * @index: node index
 * Return: size
 */
list_t *add_node_end1(list_t **hnode, const char *str, int index)
{
	list_t *new_node, *n;

	if (!hnode)
		return (NULL);

	n = *hnode;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset1((void *)new_node, 0, sizeof(list_t));
	new_node->num = index;
	if (str)
	{
		new_node->str = _strdup1(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (n)
	{
		while (n->next)
			n = n->next;
		n->next = new_node;
	}
	else
		*hnode = new_node;
	return (new_node);
}

/**
 * print_list_str1 - print the str element of list_t list
 * @hnode: Pointer first node
 * Return: size
 */
size_t print_list_str1(const list_t *hnode)
{
	size_t i = 0;

	while (hnode)
	{
		_puts1(hnode->str ? hnode->str : "(nil)");
		_puts1("\n");
		hnode = hnode->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index1 - deletes node in specific index
 * @hnode: pointer to the begining node
 * @ind: deleted node index
 * Return: 1 success, else 0
 */
int delete_node_at_index1(list_t **hnode, unsigned int ind)
{
	list_t *n, *prev_node;
	unsigned int i = 0;

	if (!hnode || !*hnode)
		return (0);

	if (!ind)
	{
		n = *hnode;
		*hnode = (*hnode)->next;
		free(n->str);
		free(n);
		return (1);
	}
	n = *hnode;
	while (n)
	{
		if (i == ind)
		{
			prev_node->next = n->next;
			free(n->str);
			free(n);
			return (1);
		}
		i++;
		prev_node = n;
		n = n->next;
	}
	return (0);
}

/**
 * free_list1 - free nodes of list
 * @hptr: Pointer of head node
 *
 * Return: void
 */
void free_list1(list_t **hptr)
{
	list_t *n, *next_node, *h;

	if (!hptr || !*hptr)
		return;
	h = *hptr;
	n = h;
	while (n)
	{
		next_node = n->next;
		free(n->str);
		free(n);
		n = next_node;
	}
	*hptr = NULL;
}
