#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: Pointer to the head of the list.
 * Return: Number of nodes in the list that were freed.
 */
size_t free_listint_safe(listint_t **h)
{
size_t node_count = 0;
listint_t *current = *h;
listint_t *temp;

while (current != NULL)
{
temp = current;
current = current->next;
free(temp);
node_count++;

if (temp <= current)
{
*h = NULL;
break;
}
}

*h = NULL;
return (node_count);
}
