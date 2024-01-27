#include "sort.h"
/**
 * merge - Merge two subarrays into a single sorted array.
 * @array: Pointer to the beginning of the array.
 * @l: Size of the left subarray.
 * @r: Size of the right subarray.
 */

void merge(int *array, size_t l, size_t r)
{
	printf("Merging...\n[left]: ");
	int left[l], right[r], i;

	for (i = 0; i < l; i++)
		left[i] = array[i];
	 print_array(left, l);

	for (i = 0; i < r; i++)
		right[i] = array[i + l];
	printf("[right]: ");
	print_array(right, r);
	i = 0;

	int j = 0, k = 0;

	while (i < l && j < r)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < l)
		array[k++] = left[i++];
	while (j < r)
		array[k++] = right[j++];
	printf("[Done]: ");
	print_array(array, l + r);
}


/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort.
 * @array: Pointer to the beginning of the array.
 * @size: Size of the array.
 */

void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	int mid = size / 2;

	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);
	if (mid <= (size - mid))
		merge(array, mid, size - mid);
}
