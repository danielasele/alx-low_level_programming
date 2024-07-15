#include <stdio.h>

/**
 * div- divides two integers
 * @a: first int
 * @b: second int
 * Return: result of division
 */
int div(int a, int b)
{
	if (b != 0)
	{
		return (a / b);
	}
	else
	{
		return (0);
	}
}
