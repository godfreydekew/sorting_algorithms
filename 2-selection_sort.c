#include "sort.h"

/**
 *selection_sort - A function that sorts an array of integers in
 *	ascending order using the Selection sort
 * @array: Pointer to the unsorted array
 * @size: Number of elements
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, indexmin;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		indexmin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[indexmin])
			{
				indexmin = j;
			}
		}
		if (indexmin != i)
		{
			int temp = array[i];

			array[i] = array[indexmin];
			array[indexmin] = temp;
		}
		print_array(array, size);
	}
}
