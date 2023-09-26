#include "sort.h"

/**
 *counting_sort - this function sorted and array with counting_sort algo
 *@array: list of integers
 *@size: size of a list of integer
 *Return: this function doesn't return any value
 */
void counting_sort(int *array, size_t size)
{
	size_t count = 0;
	int max, i;
	int *cpy_array;
	int *auxiliary_array = NULL;
	int index;
	size_t j = 0;

	max = array[0];
	while (count < size)
	{
		if (array[count] > max)
			max = array[count];
		count++;
	}
	auxiliary_array = malloc(sizeof(int) * (max + 1));
	cpy_array = malloc(sizeof(int) * size);
	i = max;
	while (i-- >= 0)
		auxiliary_array[i] = 0;
	count = 0;
	while (count < size)
	{
		cpy_array[count] = array[count];
		auxiliary_array[array[count]] = auxiliary_array[array[count]] + 1;
		count++;
	}
	i = 0;
	while (i <= max)
	{
	
		auxiliary_array[i + 1] = auxiliary_array[i] + auxiliary_array[i + 1];
		if (i == 0)
			printf("%d", auxiliary_array[i]);
		else
			printf(", %d", auxiliary_array[i]);
		i++;
	}
	j = 1;
	printf("\n");
	while (j < size)
	{
		index  = auxiliary_array[cpy_array[j]];
		printf("*%d\t", index - 1);
		array[index - 1] = *(cpy_array + j);
		auxiliary_array[cpy_array[j]] = index - 1;
		j++;
	}
	free(cpy_array);
	free(auxiliary_array);
}
