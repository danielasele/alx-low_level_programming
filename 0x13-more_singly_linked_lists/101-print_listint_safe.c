#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the head of the list.
 * Return: Number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
size_t node_count = 0;
const listint_t *current = head;
const listint_t *slow_ptr = head, *fast_ptr = head;

while (current != NULL)
{
printf("[%p] %d\n", (void *)current, current->n);
current = current->next;
node_count++;

if (slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL)
{
slow_ptr = slow_ptr->next;
fast_ptr = fast_ptr->next->next;

if (slow_ptr == fast_ptr)
{
printf("-> [%p] %d\n", (void *)slow_ptr, slow_ptr->n);
break;
}
}
}

return (node_count);
}
