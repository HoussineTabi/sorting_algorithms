#include "sort.h"
/**
 *arra_memory_location - this function will allocate memory
 *@size: size of that array
 *Return: this function will return pointer to array
 */

int *arra_memory_location(size_t size)
{
	return ((int *)malloc(sizeof(int) * size));
}
/**
 *merge - this function will merge two arrays
 *@arr: an array to merge into
 *@arrL: array left
 *@arrR: array right
 *@size: size of that array
 *@left: size of array of left
 *@right: size of array of right
 *Return: this function will return the array
 */
int *merge(int *arr, int *arrL, int *arrR, size_t size,
		size_t left, size_t right)
{
	size_t i, j, k;

	i = j = k = 0;
	while (i < size)
	{
		if (j >= left || k >= right)
			break;
		if (arrL[j] <= arrR[k])
		{
			arr[i] = arrL[j];
			i++;
			j++;
		}
		else
		{
			arr[i] = arrR[k];
			i++;
			k++;
		}
	}
	while (j < left)
	{
		arr[i] = arrL[j];
		i++;
		j++;
	}
	while (k < right)
	{
		arr[i] = arrR[k];
		k++;
		i++;
	}
	return (arr);
}
/**
 * printArray - this function will print an array
 * @array: array to print
 * @size: size of the array
 */
void printArray(int *array, size_t size)
{
	size_t i = 0;

	if (size == 0)
		return;
	while (i < size)
	{
		if (i == 0)
			printf("%d", array[i]);
		else
			printf(", %d", array[i]);
		i++;
	}
	printf("\n");
}
/**
 *merge_sort - this function will sort an array using merge algorithm
 *@array: an array that we want to sort
 *@size: size of that array
 *Return: this function will not return any value
 */
void merge_sort(int *array, size_t size)
{
	size_t left, i = 0;
	int *arrL, *arrR;

	arrL = arrR = NULL;
	if (size <= 1)
		return;
	left = size / 2;
	arrL = arra_memory_location(left);
	while (i < left)
	{
		arrL[i] = array[i];
		i++;
	}
	arrR = arra_memory_location(size - left);
	i = 0;
	while (i < size - left)
	{
		arrR[i] = array[left + i];
		i++;
	}
	i = 0;
	merge_sort(arrL, left);
	merge_sort(arrR, size - left);
	merge(array, arrL, arrR, size, left, size - left);
	printf("Merging...\n");
	printf("[left]: ");
	printArray(arrL, left);
	printf("[right]: ");
	printArray(arrR, size - left);
	printf("[Done]: ");
	printArray(array, size);
	free(arrR);
	free(arrL);
}
