#include "sort.h"

/**
 * selection_sort - function to sort an array of integers
 * using the selection sorting algorithm.
 *
 * @array: Array to be sorted
 * @size: Size of array to be sorted
 *
 * Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	int i, j, min_index;
	
	if (check_array_is_sorted(array, size))
		return;

	for (i = 0; i < (int)size; i++)
	{
		min_index = i;
		for (j = i; j < (int)size; j++)
		{
			if (array[min_index] > array[j])
				min_index = j;
		}
		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}

