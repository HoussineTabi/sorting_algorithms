#include "sort.h"

/**
 *partition - my function to partition an array
 *@array: my part array to partition
 *@start: index of start of partition
 *@end: index of end of partition
 *Return: this function return an nteger
 */
size_t partition(int *array, size_t start, size_t end)
{
	size_t pivoIndex = start, i;
	int pivot = array[end], swap;

	for (i = start; i < end; i++)
	{
		if (array[i] >= pivot)
		{
			printf("Enter\n");
			swap = array[i];
			array[i] = array[pivoIndex];
			array[pivoIndex] = swap;
			pivoIndex++;
		}
	}
	return (pivoIndex);	
}
/**
 *sortedQuickly - my function to partition an array
 *@array: my part array to partition
 *@start: index of start of partition
 *@end: index of end of partition
 *Return: this function doesn't return any value
 */
void sortedQuickly(int **array, size_t start, size_t end, size_t size)
{
	size_t pivoIndex;

	if (start < end)
	{
		pivoIndex = partition(*array, start, end);
		print_array(*array, size);
		printf("pivoIndex = %ld\n", pivoIndex);
		/*sortedQuickly(array, start, pivoIndex - 1, size);
		//sortedQuickly(array, pivoIndex + 1, end, size);*/
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
	sortedQuickly(&array, 0, size - 1, size);
}
