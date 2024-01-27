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
	size_t i;
	int max, *temp, *count;

	max = max_element(array, size);

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
	{
		free(count);
		return;
	}

	if (count == NULL || size < 2)
		return;

	for (i = 0; (int)i < max + 1; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		++count[array[i]];

	for (i = 0; (int)i < max + 1; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = size - 1; (int)i >= 0 ; i--)
		temp[--count[array[i]]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	free(temp);
	free(count);
}
