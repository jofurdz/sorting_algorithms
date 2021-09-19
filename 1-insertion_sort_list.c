#include "sort.h"

/**
 * insertion_sort_list - sorts usning insertion algorithm
 *
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp = NULL, *blah = NULL;

	if (list == NULL)
		return;
	current = (*list)->next;
	temp = current;

	while (current != NULL)
	{
		current = current->next;

		if (temp->n < temp->prev->n)

			while (temp->prev != NULL && temp->n < temp->prev->n)
			{
				blah = temp->prev;
				blah->next = temp->next;

				if (blah->prev != NULL)
					blah->prev->next = temp;
				if (temp->next != NULL)
					temp->next->prev = blah;

				temp->prev = blah->prev;
				temp->next = blah;
				blah->prev = temp;

				if (temp->prev == NULL)
					(*list) = temp;
				print_list(*list);
			}
		temp = current;
	}
}
