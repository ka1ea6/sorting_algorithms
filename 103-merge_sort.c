#include "sort.h"

void merge_sort_recursive(int *array, size_t size, int start_idx, int end_idx);
void sorter(int *array, size_t size, int start_idx, int middle_idx, int end_idx);
void copy_array(int *copy_from, int *copy_to, int copy_start, int copy_end);
void swap_array(int *a, int *b);

/**
 * merge_sort - Wrapper function for a recursive function to sort an array
 * of integers using the merge sort algorithm.
 *
 * @array: array to be sorted.
 * @size: size of the array to be sorted.
 *
 * Return: Nothing.
 */

void merge_sort(int *array, size_t size)
{
	merge_sort_recursive(array, size, 0, size);
}


/**

 * merge_sort_recursive - Function to sort an array of integers using the merge
 * sort algorithm.
 *
 * @array: array to be sorted.
 * @size: size of the array to be sorted
 * @start_idx: starting index of the sub array to be sorted
 * @end_idx: ending index of the sub array to be sorted.
 *
 * Return: Nothing..
 */

void merge_sort_recursive(int *array, size_t size, int start_idx, int end_idx)
{
	int middle_idx;

	if (end_idx - start_idx <= 1)
		return;

	middle_idx = (start_idx + end_idx) / 2;

	merge_sort_recursive(array, size, start_idx, middle_idx);
	merge_sort_recursive(array, size, middle_idx, end_idx);
	
	sorter(array, size, start_idx, middle_idx, end_idx);
}

/**
 * sorter - function to sort sub arrays and merge them.
 *
 * @array: array to be sorted.
 * @size: size of the array to be sorted.
 * @start_idx: starting index of the sub array to be sorted.
 * @middle_idx: middle point of the sub array to be sorted.
 * @end_idx: end point of the sub array to be sorted.
 *
 * Return: Nothing.
 */

void sorter(int *array, __attribute__((unused))size_t size, int start_idx, int middle_idx, int end_idx)
{
	int i, j;

	printf("Merging...\n[left]: ", start_idx, middle_idx, end_idx);
	print_array(array + start_idx, middle_idx - start_idx);
	printf("[right]: ");
	print_array(array + (middle_idx), end_idx - middle_idx);
	for (i = start_idx; i < end_idx; i++)
	{
		j = 0;

		if (i < middle_idx)
		{
			while (j < end_idx - middle_idx)
			{
				if (array[middle_idx + j] < array[i])
				{
					swap_array(&array[i], &array[middle_idx + j]);
					break;
				}
				j++;
			}
		}
			while (j < end_idx - i)
			{
				if (array[i + j] < array[i])
				{
					swap_array(&array[i + j], &array[i]);
					break;
				}
				j++;
			}
	}
	printf("[Done]: ");
	print_array(array + start_idx, end_idx - start_idx);
}
/**
 * swap_array: Funciton to swap to integers
 *
 * @a: first number to be swapped
 * @b: second number to be swapped.
 *
 * Return: Nothing.
 */

void swap_array(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
