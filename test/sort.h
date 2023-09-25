#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void selection_sort(int *, size_t);
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t **node1, listint_t *node2);
void quick_sort(int *, size_t);
void print_list(const listint_t *);
<<<<<<< HEAD
void cocktail_sort_list(listint_t **list);
=======
void shell_sort(int *, size_t);
>>>>>>> db2371e35e1cee540a778450945ddb883d9db8f1
#endif /* SORT_H */
