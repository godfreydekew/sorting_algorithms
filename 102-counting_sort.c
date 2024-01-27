#include "sort.h"

/**
 * max_element - Calculates the maximum element in array
 * @array: Pointer to the array
 * @size: Size of the array
 * Return: The maximum element
 */

int max_element(int *array, size_t size)
{
	size_t i;

	int max = array[0];

	for (i = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	return (max);
}

/**
 *counting_sort - a function that sorts an array of integers
 *	in ascending order using the Counting sort algorithm
 * @array: Pointer to the array
 * @size: Size of the array
 */

void counting_sort(int *array, size_t size)
{
	int max = max_element(array, size) + 1, i;

	int *count = malloc(sizeof(int) * max);

	int *temp = malloc(sizeof(int) * size);

	if (count == NULL)
		return;

	for (i = 0; i < max; i++)
	{
		count[i] = 0;
	}

	for (i = 0; i < size; i++)
		++count[array[i]];

	for (i = 0; i < max; i++)
		count[i] += count[i - 1];

	print_array(count, max);
	for (i = size - 1; i >= 0; i--)
		temp[--count[array[i]]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	free(temp);
	free(count);
}
