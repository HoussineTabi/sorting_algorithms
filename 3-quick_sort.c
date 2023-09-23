#include "sort.h"
/**
 * quick_sort - sorting an array using the quick sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size == 1 || !array)
		return;
	quicksort(array, size, size, array);
}
/**
 * quicksort - pomudo partition
 *
 * @array: the array to sort
 * @size: the size of he array
 */

void quicksort(int *array, size_t size,  size_t arr_size, int *array_o)
{
        size_t left, right, i;
        int pivot, swap;

	if (size <= 1)
		return;
	pivot = array[size - 1];
        left = size - 2;
        right = 0;
        for (i = 0; i < size - 1; i++)
        {
                if (left < right)
                        break;
                if (array[right] > pivot && array[left] < pivot)
                {
                        swap = array[right];
                        array[right] = array[left];
                        array[left] = swap;
                }
                else
                {
                        if (array[right] < pivot)
                                right++;
                        if (array[left] > pivot)
                                left--;
                }
        }
        array[size - 1] = array[right];
        array[right] = pivot;
	print_array(array_o, arr_size);
        quicksort(array, right, arr_size, array_o);
        quicksort((array + right + 1), size - right - 1, arr_size, array_o);
}
