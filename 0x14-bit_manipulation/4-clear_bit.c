#include "main.h"

/**
 * clear_bit - Clears the value of a given bit to 0
 * @n: Pointer to the number to change
 * @index: Index of the bit to clear (0-based)
 *
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index > (sizeof(unsigned long int) * 8 - 1))
return (-1);

*n &= ~(1UL << index);
return (1);
}
