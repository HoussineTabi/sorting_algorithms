#include "sort.h"

/**
* swap_nodes - Swap two nodes in a listint_t doubly-linked list.
* @list: A pointer that points to the head of the doubly-linked list.
* @node1: A pointer that points to the first node to swap.
* @node2: The second node to swap.
*/
void swap_nodes(listint_t **list, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*list = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
* insertion_sort_list - Sort a doubly linked list of integers
*using the insertion sort algorithm.
* @list: A pointer that points to the head of a doubly-linked list of integers.
* Description: Print the list after each swap.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *prev, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	iter = (*list)->next;
	while (iter)
	{
		tmp = iter->next;
		prev = iter->prev;
		while (prev != NULL && iter->n < prev->n)
		{
			swap_nodes(list, &prev, iter);
			print_list((const listint_t *)(*list));
		}
		iter = tmp;
	}
}
