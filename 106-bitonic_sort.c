#include "sort.h"

void swap(int *a, int *b, int dir);
void bitonic_sort_recursive(int *array, int from, size_t size, int direction);
void bitonic_merge(int *array, int from , int size, int direction);
/**
 * bitonic_sort - Function to sort an array of integers
 * using the bitonic sorting algorithm.
 *
 * @array: array to be sorted.
 * @size: Size of the array to be sorted.
 *
 * Return: Nothing.
 */

void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, 0, size, 1);
}


void bitonic_sort_recursive(int *array, int from, size_t size, int direction)
{
	int curr;

	if (size > 1)
	{
		curr = size / 2;
		bitonic_sort_recursive(array, from, curr, 1);
		bitonic_sort_recursive(array, from + curr, curr, 0);
		bitonic_merge(array, from, size, direction);
	}

}

void bitonic_merge(int *array, int from , int size, int direction)
{
	int i, j;

	if (size > 1)
	{
		print_array(array, size);
		j = size / 2;
		for (i = from;i < from + j; i++)
			swap(&array[i], &array[i+j], direction);
		bitonic_merge(array, from, j, direction);
		bitonic_merge(array, from + j, j, direction);
	}
}
void swap(int *a, int *b, int dir)
{
	int temp;

	if (dir == (*a < *b))
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
	
