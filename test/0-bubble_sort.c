#include "sort.h"

/**
 *bubble_sort - This function sort a given array
 *@array: an array to be sorted
 *@size: size of array to be sorted
 * Return: doesn't return any value
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int swap, flag = 1;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				print_array(array, size);
				flag = 1;
			}
		}
		if (!flag || i == size - 2)
			break;
		flag = 0;
	}
}
