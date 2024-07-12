#include <stdlib.h>
#include "main.h"

/**
 * add - adds two integers
 * @a: first integer
 * @b: second integer
 * Return: sum of a and b
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - subtracts two integers
 * @a: first integer
 * @b: second integer
 * Return: difference of a and b
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - multiplies two integers
 * @a: first integer
 * @b: second integer
 * Return: product of a and b
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * divide - divides two integers
 * @a: first integer
 * @b: second integer
 * Return: quotient of a and b, or 0 if b is 0
 */
int divide(int a, int b)
{
	if (b == 0)
	{
		return (0);
	}
	return (a / b);
}

/**
 * mod - returns the modulus of two integers
 * @a: first integer
 * @b: second integer
 * Return: modulus of a and b, or 0 if b is 0
 */
int mod(int a, int b)
{
	if (b == 0)
	{
		return (0);
	}
	return (a % b);
}
