#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: The list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur_tem1, *temp, *final;

	if (list == NULL || *list == NULL)
		return;

	cur_tem1 = (*list)->next;
	while (cur_tem1)
	{
		final = cur_tem1;
		cur_tem1 = cur_tem1->next;

		while (final && final->prev && final->prev->n > final->n)
		{
			temp = final->prev;
			final->prev = temp->prev;
			temp->next = final->next;

			if (temp->prev)
				temp->prev->next = final;

			if (final->next)
				final->next->prev = temp;

			temp->prev = final;
			final->next = temp;

			if (!final->prev)
				*list = final;

			print_list(*list);
		}
	}
}
