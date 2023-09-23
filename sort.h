#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void selection_sort(int *, size_t);
<<<<<<< HEAD
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t **node1, listint_t *node2);
=======
void quick_sort(int *, size_t);
>>>>>>> refs/remotes/origin/master
#endif /* SORT_H */
