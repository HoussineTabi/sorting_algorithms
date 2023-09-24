#include "sort.h"
/**
 * shell_sort - sorting an array using the shell sort
 *
 * @array: The array to sort
 * @size: The size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int swap;

	if (!array || size == 0 || size == 1)
		return;
	while (gap < size)
		gap = 3 * gap + 1;
	if (gap > size)
		gap = (gap - 1) / 3;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
			{
				swap = array[j];
				array[j] = array[j - gap];
				array[j - gap] = swap;
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
