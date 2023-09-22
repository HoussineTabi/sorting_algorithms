#include "sort.h"

/**
 * selection_sort - sorts a taible using the selection sort
 *
 * @array: the table to sort
 * @size: the size of the table
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, swap, min = 0;

	if (size >= 2)
	{
		for (i = 0; i < size - 1; i++)
		{
			min = i;
			for (j = i; j <= size - 1; j++)
			{
				if (array[j] < array[min])
					min = j;
			}
			if (min != i)
			{
				swap = array[i];
				array[i] = array[min];
				array[min] = swap;
			}
			print_array(array, size);
		}
	}
}
