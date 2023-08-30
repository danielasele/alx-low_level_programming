#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index.
 * @head: Pointer to the pointer to the head of the list.
 * @index: Index of the node to be deleted.
 * Return: 1 if succeeded, -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
unsigned int count = 0;
listint_t *current, *temp;

if (*head == NULL)
return (-1);

if (index == 0)
{
temp = *head;
*head = (*head)->next;
free(temp);
return (1);
}

current = *head;
while (current != NULL && count < index - 1)
{
current = current->next;
count++;
}

if (current == NULL || current->next == NULL)
return (-1);

temp = current->next;
current->next = temp->next;
free(temp);
return (1);
}
