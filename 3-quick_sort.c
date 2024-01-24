#include "sort.h"

/**
 *lomuto_partition - A function that partitions the list
 * @array: pointer to the array
 * @start: first index of the array
 * @end: last index of the array
 * @s: size of the aray
 * Return: index where partition occured
 */

size_t lomuto_partition(int *array, int start, int end, size_t s)
{
	int pivot = array[end];
	int pindex = start;
	size_t i;

	for (i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
			if (i != pindex)
			{
				int temp = array[pindex];

				array[pindex] =  array[i];
				array[i] = temp;
				print_array(array, s);
			}
			pindex = pindex + 1;
		}
	}

	if (pindex != end)
	{
		int temp1 = array[pindex];

		array[pindex] =  array[end];
		array[end] = temp1;
		print_array(array, s);
	}

	return (pindex);
}

/**
 * lomuto_sort - Implements the QuickSort algorithm using
 *		 Lomuto partition scheme
 * @array: The array to be sorted
 * @start: The starting index of the subarray to be sorted
 * @end: The ending index of the subarray to be sorted
 * @s: The size of the array
 */

void lomuto_sort(int *array, int start, int end, size_t s)
{

	if (start < end)
	{

		int pindex = lomuto_partition(array, start, end, s);

		lomuto_sort(array, start, pindex - 1, s);
		lomuto_sort(array, pindex + 1, end, s);

	}
}

/**
 *quick_sort - Sorts an array of integers in
 *		ascending order using the QuickSort algorithm
 *@array: The array to be sorted
 *@size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1, size);
}

