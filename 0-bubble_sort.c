#include "sort.h"

/**
 *bubble_sort - This function sort a given array
 *@array: an array to be sorted
 *@size: size of array to be sorted
 * Return: doesn't return any value
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j, flag = 0;
	int swap;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				flag = 1;
			}
		}
		if (!flag)
			break;
		flag = 0;
	}
}
