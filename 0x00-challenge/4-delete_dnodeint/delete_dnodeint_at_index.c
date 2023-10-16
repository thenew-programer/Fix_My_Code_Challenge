#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp1, *tmp2;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	p = 0;
	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}
	if (p != index)
	{
		*head = saved_head;
		return (-1);
	}
	if (0 == index)
	{
		tmp1 = (*head)->next;
		free(*head);
		*head = tmp1;
		if (tmp1 != NULL)
		{
			tmp1->prev = NULL;
		}
	}
	else
	{
		tmp1 = (*head)->prev;
		tmp2 = (*head)->next;
		tmp1->next = tmp2;
		tmp2->prev = tmp1;
		free(*head);
		*head = saved_head;
	}
	return (1);
}
