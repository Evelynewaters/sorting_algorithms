#include "sort.h"

/**
 * swapp_list - it swaps linked list nodes then prints list
 * @list: the Linked list to swap
 * @n1: node one
 * @n2: node two
 */
void swapp_list(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (n1->prev)
		n1->prev->next = n2;
	else
		(*list) = n2;
	if (n2->next)
		n2->next->prev = n1;
	n2->prev = n1->prev;
	n1->next = n2->next;
	n2->next = n1;
	n1->prev = n2;
	print_list(*list);
}
/**
 * insertion_sort_list - the Insertion sort algorithm
 * @list: the Linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list)
	{
		for (current = (*list)->next; current; current = current->next)
		{
			tmp = current;
			while (tmp->prev && current->n < tmp->prev->n)
				swapp_list(*&list, tmp->prev, tmp);
		}
	}
}
