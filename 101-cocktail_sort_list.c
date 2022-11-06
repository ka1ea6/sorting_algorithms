#include "sort.h"

/**
 * cocktail_sort_list - Function to sort a Doubly linked list
 * in ascending order using the cocktail sorting algorithm.
 *
 * @list: list to be sorted.
 *
 * Return: Nothing.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp, *last;
	int swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		temp = (*list);
		last = (*list);

		while (temp)
		{
			if (temp->next && temp->next->n < temp->n)
			{
				list_swap(temp, temp->next, list);
				print_list(*list);
				swapped = 1;
				temp = temp->prev;
			}
			last = temp;
			temp = temp->next;
		}

		while (last)
		{
			if (last->prev && last->prev->n > last->n)
			{
				list_swap(last->prev, last, list);
				print_list(*list);
				swapped = 1;
				last = last->next;
			}
			last = last->prev;
		}
	}
}

/**
 * list_swap - Function to swap two elements in a doubly linked list.
 *
 * @first_node: first node to be swapped.
 * @second_node: second node to be swapped.
 * @list: list containing the nodes.
 *
 * Return: Nothing.
 */

void list_swap(listint_t *first_node, listint_t *second_node, listint_t **list)
{
	first_node->next = second_node->next;
	if (second_node->next)
		second_node->next->prev = first_node;
	second_node->next = first_node;
	second_node->prev = first_node->prev;
	if (first_node->prev)
		first_node->prev->next = second_node;
	else
		(*list) = second_node;
	first_node->prev = second_node;
}
