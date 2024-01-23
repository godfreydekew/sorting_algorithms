#include "sort.h"

/**
 *bubble_sort -  function that sorts an array of integers in ascending order
 *@array: Array of unsorted integers
 *@size: Number of integers in the array
 *Return - None
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, x, tmp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		for (x = 0; x < (size - 1); x++)
		{
			if (array[x] > array[x + 1])
			{
				tmp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
