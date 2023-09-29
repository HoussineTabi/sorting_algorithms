#include "sort.h"

/**
 *partition - my function to partition an array
 *@A: my part array to partition
 *@start: index of start of partition
 *@end: index of end of partition
 *Return: this function return an nteger
 */
size_t partition(int *A, size_t start, size_t end)
{
	int pivot = A[end], c;
	size_t i;
	size_t pivIndex;

	pivIndex = start;
	for (i = start; i < end; i++)
	{
		if (A[i] <= pivot)
		{
			c = A[i];
			A[i] = A[pivIndex];
			A[pivIndex] = c;
			pivIndex++;
		}
	}
	c = A[end];
	A[end] = A[pivIndex];
	A[pivIndex] = c;
	return (pivIndex);
}
/**
 *sortedQuickly - this function will sort an array
 *@array: parameter pointer to the array
 *@start: start of arr
 *@end: end of array;
 *@size: size of our array
 *Return: this function doesn't return any value
 */
void sortedQuickly(int *array, size_t start, size_t end, size_t size)
{
	size_t pivoIndex;

	if (start < end)
	{
		pivoIndex = partition(array, start, end);
		sortedQuickly(array, start + 1, pivoIndex , size);
		sortedQuickly(array, pivoIndex + 1, end, size);
		print_array(array, size);
	}
}
/**
 *quick_sort_hoare - this function will sort an array
 *@array: parameter pointer to the array
 *@size: size of our array
 *Return: this function doesn't return any value
 */
void quick_sort_hoare(int *array, size_t size)
{
	sortedQuickly(array, 0, size - 1, size);
}
