#include "sort.h"
/**
 *heap_sort - this function will sort an array using heap sort algorithm
 *@array: an array that we want to sort
 *@size: size of that array
 *Return: this function will not return any value
 */
void insert_to_heap(listint_m **heap, int data)
{
	listint_m *tmp, *head;

	tmp = malloc(sizeof(listint_m));
	if (!tmp)
		return;
	tmp->prev = NULL;
	tmp->next = NULL;
	tmp->n = data;
	if (*heap == NULL)
	{
		(*heap) = tmp;
		return;
	}
	head = *heap;
	while (head)
	{
		if (head->n >= data)
		{
			if (head->prev)
				head = head->prev;
			else
			{
				head->prev = tmp;
				return;
			}
		}
		else
		{
			if (head->next)
				head = head->next;
			else
			{
				head->next = tmp;
				return;
			}
		}
	}
}
void printHeap(listint_m *heap)
{
	if (heap == NULL)
		return;
	printHeap(heap->prev);
	printHeap(heap->next);
	printf("%d\t", heap->n);
}
void heap_sort(int *array, size_t size)
{
	listint_m *heap;
	size_t count = 0;

	(void)heap;
	printf("this is my heapsort function %p \t %ld\n", (void *)array, size);

	while (count < size)
	{
		insert_to_heap(&heap, array[count]);
		printf("%d\t", array[count]);
		count = count + 1;
	}

}
