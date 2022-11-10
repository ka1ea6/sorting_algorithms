#include "sort.h"

void heapify(int *array, size_t size, int j, int i);
void swap_array(int *a, int *b);

/**
 * heap_sort - Function to sort an array of integers
 * using the heap sort algorithm.
 *
 * @array: Array to be sorted.
 * @size: Size of the array to be sorted.
 *
 * Return: Nothing.
 */

void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i >= 0; i--)
	{
		swap_array(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}

/**
 * heapify - Function to heapify the given array.
 *
 * @array: array to be heapified.
 * @size: Size of the array to be heapified.
 * @i: Largest value in array
 * @j: size of heap..
 *
 * Return: Nothing.
 */

void heapify(int *array, size_t size, int j, int i)
{
	int largest, left, right;

	left = 2 * i + 1;
	right = 2 * i + 2;
	largest = i;

	if (left < (int) j && array[left] > array[largest])
		largest = left;

	if (right < (int) j && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap_array(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, j, largest);
	}
}

/**
 * swap_array - Function to swap two numbers.
 *
 * @a: first number to swap.
 * @b: second number to swap.
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
