#include "sort.h"
/**
 *cocktail_sort_list - this function will sort a linked list
 *@list: pointer to head of a list
 *Return: this function doesn't return any value
 */
void printTail(listint_t *tail, int x)
{
	if (tail == NULL)
	{
		printf("(nil)");
		return;
	}
	printTail(tail->prev, 1);
	if (tail->prev != NULL && x == 0)
		printf("<-%d", tail->n);
	else if (tail->prev && x != 0)
	{
		printf("<=>%d", tail->n);
	}
	else
	{
		printf("<-%d", tail->n);
	}
}
void swapNodes(listint_t **list, listint_t **node1)
{
	listint_t *head, *prev, *node2 = *node1;
	printf("swap next to write place next = %d \n",  node2->n);
	head = *list;
	if (!list || !(*list) || !node1 || !(*node1))
		return;

	while (head->n < node2->n)
	{
		prev = head;
		head = head->next;
	}
	if (head == *list && prev)
	{
		head->prev = node2;
		node2->next = head;
		node2->prev = NULL;
		*list = node2;
	}
	else
	{
		prev->next = node2;
		node2->prev =  prev;
		node2->next = head;
		head->prev = node2;
	}

}
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *tail, *next, *prev;

	head = *list;
	tail = head;
	while (tail->next)
		tail = tail->next;
	next = head->next;
	prev = head;
	while (next)
	{
		if (prev->n > next->n)
		{
			prev->next = next->next;
			if (next->next)
				next->next->prev = prev;
			if (next->next)
				next->next->prev = prev;
			swapNodes(list, &next);
			next = prev;
			print_list(*list);
		}
		prev = next;
		next = next->next;
		
	}
	tail = prev;
	while (tail)
	{
		printf("tail->data = %d\n", tail->n);
		tail = tail->prev;
	}
	printf("\n");
	/*printTail(tail, 0);*/
}
