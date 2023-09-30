#include "main.h"

/**
 * flip_bits - Counts the number of bits to change to get from one number to another
 * @n: First number
 * @m: Second number
 *
 * Return: Number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int exclusive = n ^ m;
unsigned int count = 0;

while (exclusive)
{
count += exclusive & 1;
exclusive >>= 1;
}

return (count);
}
