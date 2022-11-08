#include "sort.h"

void swap(int *a, int *b);
/**
 * radix_sort - Function to sort an array of integers
 * using the radix sorting algorithm.
 *
 * @array: Array to be sorted.
 * @size: Size of array to be sorted.
 *
 * Return: Nothing.
 */

void radix_sort(int *array, size_t size)
{
	int i, j, mod_value, flag;

	mod_value = 10;
	flag = 1;
	while (flag)
	{
		flag = 0;
		for (i = 1; i < (int) size; i++)
		{
			j = i;
			while (array[j - 1] % mod_value > array[j] % mod_value)
			{
				swap(&array[j], &array[j - 1]);
				j--;
				flag = 1;
			}
		}
		if (flag)
			print_array(array, size);
		mod_value *= 10;
	}
}

/**
 * swap - Swaps two integers
 *
 * @a: first number to be swapped
 * @b: second number to be swapped.
 *
 * Return: Nothing.
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
